#include <climits>

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

class Solution {
public:
    int maxNonoverlapIntervals(vector<pair<int, int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = 0, pre_r = -1;
        for (auto& [l, r] : intervals)
        {
            if (l > pre_r)
            {
                ans ++;
                pre_r = r;
            }
        }

        return ans;
    }

    void dfs(int x, int& left, int& right, vector<bool>& vis, vector<vector<int>>& pos, vector<vector<int>>& g)
    {
        vis[x] = true;
        left = min(left, pos[x][0]);
        right = max(right, pos[x].back());

        for (int y : g[x])
        {
            if (!vis[y])
            {
                dfs(y, left, right, vis, pos, g);
            }
        }
    }

    bool maxSubstringLength(string s, int k) {
        if (k == 0)
        {
            return true;  // 提前返回
        }

        // 记录每种字母的出现位置，每个vector里面是idx
        vector<vector<int>> pos(26);  // 生成了26个vector
        for (int i = 0; i < s.size(); i ++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        // 构建有向图，注意这个i我说成字母是和真正字母表的字母是一一对应的，不需要关注具体的字母是什么
        vector<vector<int>> g(26);
        for (int i = 0; i < 26; i ++)
        {
            if (pos[i].empty())
            {
                continue;  // 没有当前这个字母
            }

            int left = pos[i][0], right = pos[i].back();  // 取出字母i的左右边界

            for (int j = 0; j < 26; j ++)
            {
                if (j == i)
                {
                    continue;
                }

                auto& q = pos[j];  // 这个是字母j的下标数组vector
                int k = std::lower_bound(q.begin(), q.end(), left) - q.begin();
                // [left, right]如果包含第j个小写字母
                if (k < q.size() && q[k] <= right)
                {
                    g[i].push_back(j);
                }
            }
        }

        // 遍历有向图
        vector<bool> vis(26);
        int left, right;

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i ++)
        {
            if (pos[i].empty())
            {
                continue;
            }

            // 如果要包含第i个小写字母，最终得到的区间是什么
            std::fill(vis.begin(), vis.end(), false);
            left = INT_MAX;
            right = 0;
            dfs(i, left, right, vis, pos, g);
            // 不能选整个s，即区间[0, n - 1]
            if (left > 0 || right < s.size() - 1)
            {
                intervals.push_back(make_pair(left, right));
            }
        }

        return maxNonoverlapIntervals(intervals) >= k;
    }
};
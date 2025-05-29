#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:

    int dfs(int x, int pre, vector<vector<int>>& memo, string& s)
    {
        int n = s.size();

        if (x >= n)
        {
            return 0;
        }

        if (memo[x][pre] != -1)
        {
            return memo[x][pre];
        }

        int res = INT_MAX;

        if (pre == 1 && s[x] == '0')
        {
            res = dfs(x + 1, 1, memo, s) + 1;
        }
        else if (pre == 1 && s[x] == '1')
        {
            res = dfs(x + 1, 1, memo, s);
        }
        else if (pre == 0 && s[x] == '1')
        {
            res = min(dfs(x + 1, 1, memo, s), dfs(x + 1, 0, memo, s) + 1);
        }
        else
        {
            res = min(dfs(x + 1, 0, memo, s), dfs(x + 1, 1, memo, s) + 1);
        }

        memo[x][pre] = res;
        return res;
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        vector<vector<int>> memo(n, vector<int>(2, -1));
        int pre = 0;

        int res = dfs(0, pre, memo, s);

        return res;
    }
};

int main(void) {
    Solution solution;
    cout << boolalpha << solution.minFlipsMonoIncr("00110") << endl;
    return 0;
}
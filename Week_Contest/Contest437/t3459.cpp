class Solution {

    static constexpr int DIRS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

public:
    int dfs(int i, int j, int k, bool can_turn, int target, vector<vector<int>>& grid, vector<vector<array<array<int, 2>, 4>>>& memo)
    {
        i += DIRS[k][0];
        j += DIRS[k][1];

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != target)
        {
            return 0;
        }

        int& res = memo[i][j][k][can_turn];  // 注意这里用了引用
        if (res)
        {
            return res;  // 之前算过
        }

        res = dfs(i, j, k, can_turn, 2 - target, grid, memo);

        if (can_turn)
        {
            res = max(res, dfs(i, j, (k + 1) % 4, false, 2 - target, grid, memo));
        }

        res ++;  // 加上当前位置

        return res;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector memo(m, vector<array<array<int, 2>, 4>>(n));

        int ans = 0;
        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k ++)
                    {
                        ans = max(ans, dfs(i, j, k, true, 2, grid, memo) + 1);
                    }
                }
            }
        }

        return ans;
    }
};
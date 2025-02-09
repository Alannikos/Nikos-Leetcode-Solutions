class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
    
            // 枚举左下角三角形的对角线
            for (int i = 0; i < n; i ++)
            {
                priority_queue<int> tmp;
                for (int j = 0; i + j < n; j ++)
                {
                    tmp.push(grid[j + i][j]);
                }
                for (int j = 0; i + j < n; j ++)
                {
                    grid[j + i][j] = tmp.top();
                    tmp.pop();
                }
            }
    
            // 枚举右上角三角形的对角线
            for (int i = 1; i < n; i ++)
            {
                priority_queue<int, vector<int>, greater<int>> tmp;
                for (int j = 0; i + j < n; j ++)
                {
                    tmp.push(grid[j][i + j]);
                }
    
                for (int j = 0; i + j < n; j ++)
                {
                    grid[j][i + j] = tmp.top();
                    tmp.pop();
                }
            }
    
            return grid;
        }
    };
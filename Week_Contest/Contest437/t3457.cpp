class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            long long res = 0;
            int n = pizzas.size();
            int day = n / 4;   // 代表有多少天
    
            sort(pizzas.begin(), pizzas.end());
    
            int idx = n - 1;
            int odd = (day + 1) / 2;
            int even = day / 2;
    
            // 先取出奇数天的重量
            for (int i = 0; i < odd; i ++)
            {
                res += pizzas[idx --];
            }
    
            // 再取出偶数天的重量
            for (int i = 0; i < even; i ++)
            {
                res += pizzas[-- idx];
                idx --;
            }
    
            return res;
        }
    };
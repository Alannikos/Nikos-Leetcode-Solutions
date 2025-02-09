class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int max_num = 0;
            for (int i = 0; i < groups.size(); i ++)
            {
                if (groups[i] > max_num)
                {
                    max_num = groups[i];
                }
            }
    
            vector<int> target(max_num + 1, -1);
    
            for (int i = 0; i < elements.size(); i ++)
            {
                int x = elements[i];
                if (x > max_num || target[x] >= 0)
                {
                    continue;
                }
    
                for (int y = x; y <= max_num; y += x)
                {
                    if (target[y] < 0)
                    {
                        target[y] = i;
                    }
                }
            }
    
            for (int& x : groups)
            {
                x = target[x];
            }
    
            return groups;
        }
    };

    
class Solution {
    public:
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            int cnt = 0;
            int left = 0, right = 0;
            
            for (; right < n; right ++)
            {
                if (s[right] == s[left])
                {
                    cnt ++;
                    continue;
                }
                else
                {
                    if (cnt == k)
                    {
                        return true;
                    }
                    else
                    {
                        left = right;
                        cnt = 1;
                        continue;
                    }
                }
            }
            
            if (cnt == k)
            {
                return true;
            }
            
            return false;
        }
    };
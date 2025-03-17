class Solution {
    public:
    
        int cache[50];
    
        int f(int n) {
            if (n < 0) return 0;
            if (n == 0) return 1;
            int& ret = cache[n];
            if (ret != -1) return ret;
            ret = 0;
            
            ret += f(n-1) + f(n-2);
            return ret;
        }
    
        int climbStairs(int n) {
            memset(cache, -1, sizeof(cache));
            return f(n);
        }
    };
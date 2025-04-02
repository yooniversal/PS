class Solution {
    public:
        int cache[405][2];
    
        int f(vector<int>& nums, int n, int prev) {
            if (n >= nums.size()) return 0;
            int& ret = cache[n][prev];
            if (ret != -1) return ret;
            ret = 0;
    
            if (prev) {
                ret = max(ret, f(nums, n+1, 0));
            } else {
                ret = max(ret, f(nums, n+1, 0));
                ret = max(ret, f(nums, n+1, 1) + nums[n]);
            }
    
            return ret;
        }
    
        int rob(vector<int>& nums) {
            memset(cache, -1, sizeof(cache));
            return f(nums, 0, 0);
        }
    };
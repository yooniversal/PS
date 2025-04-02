class Solution {
    public:
        int cache[1005][2][2];
    
        int f(vector<int>& nums, int n, int prev, int start) {
            if (n >= nums.size()) return 0;
            if (n == nums.size() - 1) {
                if (prev || start) return 0;
                return nums[n];
            }
            int& ret = cache[n][prev][start];
            if (ret != -1) return ret;
            ret = 0;
    
            if (prev) {
                ret = max(ret, f(nums, n+1, 0, start));
            } else {
                ret = max(ret, f(nums, n+1, 0, start));
                ret = max(ret, f(nums, n+1, 1, start) + nums[n]);
            }
    
            return ret;
        }
    
        int rob(vector<int>& nums) {
            memset(cache, -1, sizeof(cache));
            return max(f(nums, 1, 0, 0), f(nums, 1, 1, 1) + nums[0]);
        }
    };
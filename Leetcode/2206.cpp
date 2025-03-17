class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
    
            int prev = nums[0];
            int cnt = 1;
            for (int i=1; i<nums.size(); i++) {
                if (prev == nums[i]) {
                    cnt++;
                    continue;
                }
    
                if (cnt % 2 != 0) return false;
    
                prev = nums[i];
                cnt = 1;
            }
    
            if (cnt % 2 != 0) return false;
    
            return true;
        }
    };
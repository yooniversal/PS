class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            vector<int> newNums;
    
            int cnt = 0;
            int prev = -10005;
            for (int i=0; i<nums.size(); i++) {
                if (prev != nums[i]) {
                    cnt = 1;
                    prev = nums[i];
                    newNums.push_back(nums[i]);
                    continue;
                }
    
                cnt++;
                prev = nums[i];
    
                if (cnt <= 2) newNums.push_back(nums[i]);
            }
    
            nums = newNums;
    
            return nums.size();
        }
    };
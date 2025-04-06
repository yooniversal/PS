class Solution {
    public:
        int bs(vector<int>& nums, int l, int r, int target) {
            while (l <= r) {
                int mid = (l+r) / 2;
                if (mid >= nums.size()) break;
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return -1;
        }
    
        int findLeftPosition(vector<int>& nums, int cur) {
            int ret = 0;
    
            int v = nums[cur];
            for (int i=cur; i>=0; i--) {
                if (nums[i] == v) {
                    ret = i;
                    continue;
                }
                break;
            }
    
            return ret;
        }
    
        int findRightPosition(vector<int>& nums, int cur) {
            int ret = 0;
    
            int v = nums[cur];
            for (int i=cur; i<nums.size(); i++) {
                if (nums[i] == v) {
                    ret = i;
                    continue;
                }
                break;
            }
    
            return ret;
        }
        
        vector<int> searchRange(vector<int>& nums, int target) {
            int position = bs(nums, 0, nums.size(), target);
            if (position == -1) return {-1, -1};
            return {findLeftPosition(nums, position), findRightPosition(nums, position)};
        }
    };
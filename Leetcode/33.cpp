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
    
        int search(vector<int>& nums, int target) {
            int k = 0;
            for (int i=0; i<nums.size()-1; i++) {
                if (nums[i] > nums[i+1]) {
                    k = i;
                    break;
                }
            }
    
            int ret = 0;
            ret = bs(nums, 0, k, target);
            if (ret != -1) return ret;
    
            ret = bs(nums, k+1, nums.size(), target);
            return ret;
        }
    };
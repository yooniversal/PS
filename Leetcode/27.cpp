class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int ret = 0;
            vector<int> arr;
    
            for (int& n : nums) {
                if (n == val) continue;
                arr.push_back(n);
            }
            ret = arr.size();
    
            while (arr.size() < nums.size()) {
                arr.push_back(0);
            }
            nums = arr;
    
            return ret;
        }
    };
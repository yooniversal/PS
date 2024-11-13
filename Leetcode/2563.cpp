class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ret = 0LL;

        sort(nums.begin(), nums.end());

        vector<int>::iterator start = nums.begin();
        for (int i=0; i<nums.size()-1; i++) {
            start++;
            int L = lower_bound(start, nums.end(), lower - nums[i]) - nums.begin();
            int R = upper_bound(start, nums.end(), upper - nums[i]) - nums.begin();
            ret += R - L;
        }

        return ret;
    }
};
class Solution {
public:
    int len;

    int nextIndex(int cur, int value) {
        if (value < 0 && -value > len) value = -(-value % len);
        cur += value;
        
        if (value < 0) {
            return cur < 0 ? len + cur : cur;
        }
        return cur % len;
    }

    vector<int> constructTransformedArray(vector<int>& nums) {
        len = nums.size();
        vector<int> ret(len, 0);

        for (int i=0; i<nums.size(); i++) {
            ret[i] = nums[nextIndex(i, nums[i])];
        }

        return ret;
    }
};
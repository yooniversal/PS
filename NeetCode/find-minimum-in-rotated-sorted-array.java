class Solution {
    public int findMin(int[] nums) {
        int ret = 1001;
        int l=0, r=nums.length-1;
        while (l <= r) {
            int m = (l+r) / 2;
            if (nums[l] <= nums[m]) {
                ret = Math.min(ret, nums[l]);
                if (nums[m] < nums[r]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                ret = Math.min(ret, nums[m]);
                if (nums[m] < nums[r]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }

        return ret;
    }
}

class Solution {
    public int removeDuplicates(int[] nums) {
        int ret = 0;
        int prev = -101;

        for (int i=0; i<nums.length; i++) {
            if (prev == nums[i]) continue;
            prev = nums[i];
            nums[ret++] = prev;
        }

        return ret;
    }
}
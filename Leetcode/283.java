class Solution {
    public void moveZeroes(int[] nums) {
        int[] ret = new int[nums.length];
        
        int retIdx = 0;
        for (int i=0; i<nums.length; i++) {
            if (nums[i] == 0) {
                continue;
            }

            ret[retIdx++] = nums[i];
        }

        for (int i=0; i<ret.length; i++) {
            nums[i] = ret[i];
        }
    }
}
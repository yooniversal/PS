class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ret = new int[nums.length];

        for (int i=0; i<nums.length; i++) {
            int mult = 1;
            for (int j=0; j<nums.length; j++) {
                if (i == j) continue;
                mult *= nums[j];
            }
            ret[i] = mult;
        }

        return ret;
    }
}  

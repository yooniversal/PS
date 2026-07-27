class Solution {
    public int maxProduct(int[] nums) {
        int ret = 0;
        for (int i=0; i<nums.length; i++) {
            for (int j=i+1; j<nums.length; j++) {
                ret = Math.max(ret, (nums[i]-1) * (nums[j]-1));
            }
        }

        return ret;
    }
}

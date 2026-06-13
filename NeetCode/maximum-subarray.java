class Solution {
    public int maxSubArray(int[] nums) {
        int ret = -1000;

        int[] prefixSum = new int[1005];
        prefixSum[0] = nums[0];
        for (int i=1; i<nums.length; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for (int i=0; i<nums.length; i++) {
            ret = Math.max(ret, nums[i]);
            int sum = nums[i];
            for (int j=i+1; j<nums.length; j++) {
                sum += nums[j];
                ret = Math.max(ret, sum);
            }
        }

        return ret;
    }
}

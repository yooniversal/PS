class Solution {
    public int maxSubArray(int[] nums) {
        int ret = -10005;

        int sum = 0;
        for (int n : nums) {
            sum += n;
            if (sum < n) sum = n;
            ret = Math.max(ret, sum);
        }

        return ret;
    }
}

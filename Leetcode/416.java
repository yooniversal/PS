class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        boolean[] dp = new boolean[target+1];
        dp[0] = true;

        for (int n : nums) {
            for (int i=target; i>=n; i--) {
                if (dp[i]) continue;
                dp[i] = dp[i - n];
            }
        }

        return dp[target];
    }
}

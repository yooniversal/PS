class Solution {

    private boolean[] cache;
    private boolean ret;

    public boolean canPartition(int[] nums) {
        cache = new boolean[5005];
        ret = false;

        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 == 1) return false;

        int halfSum = sum / 2;

        Arrays.sort(nums);
        searchSubset(nums, halfSum, 0, 0);

        return ret;
    }

    private void searchSubset(int[] nums, int halfSum, int start, int currentSum) {
        if (currentSum == halfSum) {
            ret = true;
            return;
        }
        if (start >= nums.length) return;
        if (ret || cache[currentSum]) return;

        searchSubset(nums, halfSum, start + 1, currentSum + nums[start]);
        searchSubset(nums, halfSum, start + 1, currentSum);
        cache[currentSum] = true;
    }
}

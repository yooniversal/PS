class Solution {

    private int[][] cache;
    private int totalSum;

    public int findTargetSumWays(int[] nums, int target) {
        totalSum = 0;
        for (int num : nums) totalSum += num;

        cache = new int[21][40001];
        for (int i=0; i<21; i++) {
            Arrays.fill(cache[i], -1);
        }

        return f(0, 0, target, nums);
    }

    private int f(int index, int curSum, int target, int[] nums) {
        if (index == nums.length) {
            return curSum == target ? 1 : 0;
        }

        int offsetSum = curSum + totalSum; // 음수 인덱스 방지
        if (cache[index][offsetSum] != -1) {
            return cache[index][offsetSum];
        }

        int add = f(index + 1, curSum + nums[index], target, nums);
        int subtract = f(index + 1, curSum - nums[index], target, nums);

        return cache[index][offsetSum] = add + subtract;
    }
}

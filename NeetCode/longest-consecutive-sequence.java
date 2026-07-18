class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        Arrays.sort(nums);

        int ret = 1;
        int cur = 1;
        int prev = nums[0];
        for (int n : nums) {
            if (prev == n) continue;
            if (n - prev == 1) ret = Math.max(ret, ++cur);
            else cur = 1;
            prev = n;
        }

        return ret;
    }
}

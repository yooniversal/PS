class Solution {

    private static int[][] cache;

    public int rob(int[] nums) {
        cache = new int[105][2];
        for (int i=0; i<105; i++) cache[i][0] = cache[i][1] = -1;

        return Math.max(f(nums, 0, 1), f(nums, 1, 0));
    }

    public int f(int[] nums, int cur, int checkStart) {
        if (cur >= nums.length) return 0;
        if (nums.length > 1 && cur == nums.length-1 && checkStart == 1) return 0;
        if (cache[cur][checkStart] != -1) return cache[cur][checkStart];
        cache[cur][checkStart] = 0;

        cache[cur][checkStart] = Math.max(cache[cur][checkStart], f(nums, cur+2, checkStart) + nums[cur]);
        cache[cur][checkStart] = Math.max(cache[cur][checkStart], f(nums, cur+1, checkStart));
        return cache[cur][checkStart];
    }
}

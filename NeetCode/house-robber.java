class Solution {

    private static int[][] cache;

    public int rob(int[] nums) {
        cache = new int[105][2];
        for (int i=0; i<105; i++) {
            cache[i][0] = cache[i][1] = -1;
        }

        return Math.max(f(nums, 0, 0), f(nums, 1, 0));
    }

    public int f(int[] nums, int cur, int selectedPrev) {
        if (cur >= nums.length) return 0;
        if (cache[cur][selectedPrev] != -1) return cache[cur][selectedPrev];
        cache[cur][selectedPrev] = 0;

        if (selectedPrev == 0) cache[cur][selectedPrev] = Math.max(cache[cur][selectedPrev], f(nums, cur+1, 1) + nums[cur]);
        cache[cur][selectedPrev] = Math.max(cache[cur][selectedPrev], f(nums, cur+1, 0));

        return cache[cur][selectedPrev];
    }
}

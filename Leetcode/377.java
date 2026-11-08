class Solution {

    private int[] cache;

    public int combinationSum4(int[] nums, int target) {
        cache = new int[1005];
        Arrays.fill(cache, -1);
        return f(nums, target);
    }

    private int f(int[] nums, int cur) {
        if (cur < 0) return 0;
        if (cur == 0) return 1;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 0;

        for (int n : nums) {
            cache[cur] += f(nums, cur - n);
        }

        return cache[cur];
    }
}

class Solution {

    private static int[] cache;

    public int minCostClimbingStairs(int[] cost) {
        cache = new int[105];
        for (int i=0; i<105; i++) cache[i] = -1;

        return Math.min(f(cost, 0), f(cost, 1));
    }

    public int f(int[] cost, int cur) {
        if (cur >= cost.length) return 0;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 987654321;

        cache[cur] = Math.min(cache[cur], f(cost, cur+1) + cost[cur]);
        cache[cur] = Math.min(cache[cur], f(cost, cur+2) + cost[cur]);

        return cache[cur];
    }
}

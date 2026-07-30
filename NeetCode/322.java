class Solution {

    private int[] cache;
    
    private static final int MAX = 987654321;

    public int coinChange(int[] coins, int amount) {
        cache = new int[10005];
        for (int i=0; i<10005; i++) cache[i] = -1;

        int ret = f(coins, amount);
        return ret >= MAX ? -1 : ret;
    }

    private int f(int[] coins, int cur) {
        if (cur < 0) return MAX;
        if (cur == 0) return 0;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = MAX;

        for (int c : coins) {
            cache[cur] = Math.min(cache[cur], f(coins, cur - c) + 1);
        }

        return cache[cur];
    }
}

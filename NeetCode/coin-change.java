class Solution {

    private static int[] cache;
    private static final int INF = 987654321;

    public int coinChange(int[] coins, int amount) {
        cache = new int[10005];
        for (int i=0; i<10005; i++) cache[i] = -1;

        int ret = f(coins, amount);
        return ret >= INF ? -1 : ret;
    }

    public int f(int[] coins, int rem) {
        if (rem < 0) return INF;
        if (rem == 0) return 0;
        if (cache[rem] != -1) return cache[rem];
        cache[rem] = INF;

        for (int c : coins) {
            cache[rem] = Math.min(cache[rem], f(coins, rem - c) + 1);
        }
        cache[rem] = Math.min(cache[rem], f(coins, rem));

        return cache[rem];
    }
}

class Solution {

    private int[][] cache;

    public int change(int amount, int[] coins) {
        cache = new int[amount+1][coins.length];
        for (int i=0; i<amount+1; i++) {
            for (int j=0; j<coins.length; j++) {
                cache[i][j] = -1;
            }
        }
        return f(0, 0, amount, coins);
    }

    private int f(int cur, int start, int amount, int[] coins) {
        if (cur > amount) return 0;
        if (cur == amount) return 1;
        if (cache[cur][start] != -1) return cache[cur][start];
        cache[cur][start] = 0;

        for (int i=start; i<coins.length; i++) {
            cache[cur][start] += f(cur + coins[i], i, amount, coins);
        }


        return cache[cur][start];
    }
}

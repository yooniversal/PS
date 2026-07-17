class Solution {

    private int[][] dp;

    public int uniquePaths(int m, int n) {
        dp = new int[105][105];
        for (int i=0; i<105; i++) {
            for (int j=0; j<105; j++) {
                dp[i][j] = -1;
            }
        }

        return f(m - 1, n - 1);
    }

    private int f(int a, int b) {
        if (a < 0 || b < 0) return 0;
        if (a == 0 && b == 0) return 1;
        if (dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0;

        dp[a][b] += f(a-1, b);
        dp[a][b] += f(a, b-1);

        return dp[a][b];
    }
}

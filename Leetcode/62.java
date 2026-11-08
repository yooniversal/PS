class Solution {

    private int[][] cache;
    private int N, M;

    public int uniquePaths(int m, int n) {
        N = m; M = n;
        cache = new int[m][n];
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) cache[i][j] = -1;

        return f(0, 0);
    }

    private int f(int x, int y) {
        if (x == N-1 && y == M-1) return 1;
        if (x >= N || y >= M) return 0;
        if (cache[x][y] != -1) return cache[x][y];
        cache[x][y] = 0;

        cache[x][y] += f(x+1, y);
        cache[x][y] += f(x, y+1);

        return cache[x][y];
    }
}

class Solution {

    private static int ret;
    private static int currentSize;
    private static boolean[][] chk;
    private static int[] dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};

    public int maxAreaOfIsland(int[][] grid) {
        ret = 0;
        currentSize = 0;
        chk = new boolean[55][55];

        for (int x=0; x<grid.length; x++) {
            for (int y=0; y<grid[0].length; y++) {
                if (grid[x][y] == 0 || chk[x][y]) continue;
                chk[x][y] = true;
                currentSize = 0;
                DFS(grid, x, y);
                ret = Math.max(ret, currentSize);
            }
        }

        return ret;
    }

    public void DFS(int[][] grid, int x, int y) {
        currentSize++;
        for (int d=0; d<4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (OOB(grid, nx, ny) || grid[nx][ny] == 0) continue;
            if (chk[nx][ny]) continue;
            chk[nx][ny] = true;
            DFS(grid, nx, ny);
        }
    }

    public boolean OOB(int[][] grid, int x, int y) {
        return x<0 || x>=grid.length || y<0 || y>=grid[0].length;
    }
}

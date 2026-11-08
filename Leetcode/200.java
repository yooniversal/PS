class Solution {

    private int N, M;
    private boolean[][] chk;
    private int[] dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};

    public int numIslands(char[][] grid) {
        N = grid.length; M = grid[0].length;
        chk = new boolean[305][305];
        
        int ret = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == '0' || chk[i][j]) continue;
                chk[i][j] = true;
                DFS(grid, i, j);
                ret++;
            }
        }

        return ret;
    }

    private void DFS(char[][] grid, int x, int y) {
        for (int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if (OOB(nx, ny) || grid[x][y] == '0' || chk[nx][ny]) continue;
            chk[nx][ny] = true;
            DFS(grid, nx, ny);
        }
    }

    private boolean OOB(int x, int y) {
        return x<0 || x>=N || y<0 || y>=M;
    }
}

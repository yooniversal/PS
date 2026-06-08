class Solution {

    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};

    public int numIslands(char[][] grid) {
        int ret = 0;

        for (int x=0; x<grid.length; x++) {
            for (int y=0; y<grid[0].length; y++) {
                if (grid[x][y] == '0') continue;
                BFS(grid, x, y);
                ret++;
            }
        }

        return ret;
    }

    public void BFS(char[][] grid, int x, int y) {
        grid[x][y] = '0';

        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (OOB(grid, nx, ny) || grid[nx][ny] == '0') continue;
            BFS(grid, nx, ny);
        }
    }

    public boolean OOB(char[][] grid, int x, int y) {
        return x<0 || x>=grid.length || y<0 || y>=grid[0].length;
    }
}

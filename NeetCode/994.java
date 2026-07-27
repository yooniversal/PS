class Solution {
    public int orangesRotting(int[][] grid) {
        int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        boolean[][] chk = new boolean[15][15];
        Queue<Pair> q = new LinkedList<>();
        
        int aliveCnt = 0;
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++) {
                if (grid[i][j] == 1) aliveCnt++;
                else if (grid[i][j] == 2) {
                    chk[i][j] = true;
                    q.add(new Pair(i, j, 0));
                }
            }
        }

        int ret = 0;

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            ret = Math.max(ret, cur.level);

            for (int d=0; d<4; d++) {
                int nx = cur.x + dx[d], ny = cur.y + dy[d];
                if (OOB(grid, nx, ny) || grid[nx][ny] != 1 || chk[nx][ny]) continue;
                chk[nx][ny] = true;
                aliveCnt--;
                q.add(new Pair(nx, ny, cur.level + 1));
            }
        }

        return aliveCnt != 0 ? -1 : ret;
    }

    private boolean OOB(int[][] grid, int x, int y) {
        return x<0 || x>=grid.length || y<0 || y>=grid[0].length;
    }

    class Pair {
        int x, y, level;
    
        public Pair(int x, int y, int level) {
            this.x = x;
            this.y = y;
            this.level = level;
        }
    }
}

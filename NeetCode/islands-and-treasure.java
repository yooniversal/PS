class Solution {

    private static int INF = 2147483647;
    private static int[] dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};

    public void islandsAndTreasure(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++) {
                if (grid[i][j] == 0) q.add(new Pair(i, j, 0));
            }
        }

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            
            for (int d=0; d<4; d++) {
                int nx = cur.x+dx[d], ny = cur.y+dy[d];
                if (OOB(grid, nx, ny) || grid[nx][ny] != INF) continue;
                grid[nx][ny] = cur.cnt + 1;
                q.add(new Pair(nx, ny, cur.cnt+1));
            }
        }
    }

    public boolean OOB(int[][] grid, int x, int y) {
        return x<0 || x>=grid.length || y<0 || y>=grid[0].length;
    }

    class Pair {
        int x, y, cnt;
        Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

        public String toString() {
            return "x=" + x + " y=" + y + " cnt=" + cnt;
        }
    }
}

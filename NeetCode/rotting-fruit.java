class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();

        int alive = 0;
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++) {
                if (grid[i][j] == 1) alive++;
                if (grid[i][j] == 2) q.add(new Pair(i, j, 0));
            }
        }

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int round = 0;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            round = Math.max(round, cur.cnt);
            
            for (int d=0; d<4; d++) {
                int nx=cur.x+dx[d], ny=cur.y+dy[d];
                if (OOB(grid, nx, ny) || grid[nx][ny] != 1) continue;
                alive--;
                grid[nx][ny] = 2;
                q.add(new Pair(nx, ny, cur.cnt+1));
            }
        }

        return alive > 0 ? -1 : round;
    }

    public boolean OOB(int[][] grid, int x, int y) {
        return x<0 || x>=grid.length || y<0 || y>=grid[0].length;
    }

    class Pair {
        int x, y, cnt;
    
        public Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}

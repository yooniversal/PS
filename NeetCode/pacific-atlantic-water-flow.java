class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> ret = new ArrayList<>();

        for (int x=0; x<heights.length; x++) {
            for (int y=0; y<heights[0].length; y++) {
                if (BFS(heights, x, y)) {
                    ret.add(List.of(x, y));
                }
            }
        }

        return ret;
    }

    public boolean BFS(int[][] heights, int sx, int sy) {
        boolean[][] chk = new boolean[heights.length][heights[0].length];
        chk[sx][sy] = true;
        
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sx, sy));

        boolean reachedPacific = false;
        boolean reachedAtlantic = false;

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            if (reachedPacific && reachedAtlantic) break;

            int[] dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
            for (int d=0; d<4; d++) {
                int nx=cur.x+dx[d], ny = cur.y+dy[d];
                if (reachPacific(heights, nx, ny)) {
                    reachedPacific = true;
                    continue;
                }
                if (reachAtlantic(heights, nx, ny)) {
                    reachedAtlantic = true;
                    continue;
                }
                if (chk[nx][ny] || heights[nx][ny] > heights[cur.x][cur.y]) continue;
                chk[nx][ny] = true;

                q.add(new Pair(nx, ny));
            }
        }

        return reachedPacific && reachedAtlantic;
    }

    public boolean reachAtlantic(int[][] heights, int x, int y) {
        return x<0 || y<0;
    }

    public boolean reachPacific(int[][] heights, int x, int y) {
        return x>=heights.length || y>=heights[0].length;
    }

    class Pair {
        int x, y;
    
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

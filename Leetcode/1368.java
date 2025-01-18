class Solution {

    static int N, M;
    static int[] dx = {0, 0, 0, 1, -1};
    static int[] dy = {0, 1, -1, 0, 0};
    static boolean[][] chk = new boolean[105][105];

    public int minCost(int[][] grid) {
        N = grid.length;
        M = grid[0].length;
        int CNT_LIMIT = N + M - 2;

        for (int i=0; i<105; i++) for (int j=0; j<105; j++)
            chk[i][j] = false;

        Deque<S> q = new ArrayDeque<>();
        q.addFirst(new S(0, 0, 0));
        
        while (!q.isEmpty()) {
            S cur = q.pollFirst();

            if (chk[cur.x][cur.y]) continue;
            chk[cur.x][cur.y] = true;
            
            if (cur.cnt >= CNT_LIMIT) break;
            if (isEnd(cur.x, cur.y)) return cur.cnt;

            int nx = cur.x + dx[grid[cur.x][cur.y]];
            int ny = cur.y + dy[grid[cur.x][cur.y]];
            if (!OOB(nx, ny) && !chk[nx][ny]) {
                q.addFirst(new S(nx, ny, cur.cnt));
            }

            for (int i=1; i<=4; i++) {
                nx = cur.x + dx[i];
                ny = cur.y + dy[i];
                if (OOB(nx, ny) || chk[nx][ny]) continue;

                q.addLast(new S(nx, ny, cur.cnt + 1));
            }
        }

        return CNT_LIMIT;
    }

    public boolean isEnd(int x, int y) {
        return x == N-1 && y == M-1;
    }

    public boolean OOB(int x, int y) {
        return x<0 || x>=N || y<0 || y>=M;
    }

    class S {
        int x, y, cnt;

        S(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}
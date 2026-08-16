class Solution {
    int m, n;
    char[][] board;
    String word;
    boolean[][] visited;

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    boolean ret;

    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.word = word;
        ret = false;

        m = board.length;
        n = board[0].length;
        visited = new boolean[m][n];

        for (int x = 0; x < m; x++) {
            if (ret) break;
            for (int y = 0; y < n; y++) {
                if (board[x][y] != word.charAt(0)) continue;
                if (ret) break;

                visited[x][y] = true;
                dfs(x, y, 0);
                visited[x][y] = false;
            }
        }

        return ret;
    }

    private void dfs(int x, int y, int idx) {
        if (idx == word.length() - 1) {
            ret = true;
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (ret) return;
            if (OOB(nx, ny) || visited[nx][ny]) continue;
            if (board[nx][ny] != word.charAt(idx + 1)) continue;
            visited[nx][ny] = true;
            dfs(nx, ny, idx + 1);
            visited[nx][ny] = false;
        }
    }

    private boolean OOB(int x, int y) {
        return x < 0 || x >= m || y < 0 || y >= n;
    }
}

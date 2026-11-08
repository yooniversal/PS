class Solution {
    private static int N, M;
    private final int[] dx = {-1, 1, 0, 0};
    private final int[] dy = {0, 0, 1, -1};

    public void solve(char[][] board) {
        N = board.length;
        M = board[0].length;

        // 1. 가장자리 O 탐색
        for (int i = 0; i < N; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][M - 1] == 'O') dfs(board, i, M - 1);
        }
        for (int j = 0; j < M; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[N - 1][j] == 'O') dfs(board, N - 1, j);
        }

        // 2. 변경
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';   // O -> X
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';   // T -> O
                }
            }
        }
    }

    private void dfs(char[][] board, int x, int y) {
        board[x][y] = 'T';

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!OOB(nx, ny) && board[nx][ny] == 'O') {
                dfs(board, nx, ny);
            }
        }
    }

    private boolean OOB(int x, int y) {
        return x < 0 || x >= N || y < 0 || y >= M;
    }
}

class Solution {

    private static boolean[][] chk;

    public void solve(char[][] board) {
        if (board == null || board.length == 0) return;
        
        int n = board.length;
        int m = board[0].length;

        chk = new boolean[n+5][m+5];
        
        for (int i=0; i<n; i++) {
            if (i == 0 || i == n-1) {
                for (int j=0; j<m; j++) {
                    if (board[i][j] == 'X') continue;
                    // chk[i][j] = true;
                    dfs(board, i, j);
                }
            } else {
                if (board[i][0] == 'O') {
                    dfs(board, i, 0);
                }
                if (board[i][m-1] == 'O') {
                    dfs(board, i, m-1);
                }
            }
        }

        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                if (chk[i][j]) continue;
                board[i][j] = 'X';
            }
        }
    }
    
    public void dfs(char[][] board, int x, int y) {
        int n = board.length;
        int m = board[0].length;

        int[] dx={-1,1,0,0}, dy={0,0,1,-1};
        for (int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if (OOB(board, nx, ny) || board[nx][ny] == 'X' || chk[nx][ny]) continue;
            if (nx==0 || nx==n-1 || ny==0 || ny==m-1) continue;
            chk[nx][ny] = true;
            dfs(board, nx, ny);
        }
    }

    public boolean OOB(char[][] board, int x, int y) {
        return x<0 || x>=board.length || y<0 || y>=board[0].length;
    }
}

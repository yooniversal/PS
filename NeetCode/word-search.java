class Solution {

    private static char[][] B;
    private static String W;
    private static boolean[][] chk;
    private static boolean ret;
    private static int dx[]={-1,1,0,0}, dy[]={0,0,1,-1};

    public boolean exist(char[][] board, String word) {
        B = board;
        W = word;
        chk = new boolean[10][10];
        ret = false;

        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    chk[i][j] = true;
                    StringBuilder sb = new StringBuilder();
                    sb.append(board[i][j]);
                    DFS(i, j, sb, 1);
                    chk[i][j] = false;
                }
            }
        }

        return ret;
    }

    public void DFS(int x, int y, StringBuilder sb, int cur) {
        if (ret) return;
        if (cur >= W.length()) {
            ret = true;
            return;
        }

        for (int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if (OOB(nx, ny) || chk[nx][ny] || B[nx][ny] != W.charAt(cur)) continue;
            chk[nx][ny] = true;
            sb.append(B[nx][ny]);
            DFS(nx, ny, sb, cur+1);
            sb.setLength(sb.length()-1);
            chk[nx][ny] = false;
        }
    }

    public boolean OOB(int x, int y) {
        return x<0 || x>=B.length || y<0 || y>=B[0].length;
    }
}

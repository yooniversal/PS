class Solution {
    
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static boolean[][] chk;
    static int N, M;
    static List<Integer> ret;

    public List<Integer> spiralOrder(int[][] matrix) {
        N = matrix.length;
        M = matrix[0].length;
        ret = new ArrayList<>();

        chk = new boolean[N+5][M+5];
        for (int i=0; i<N+5; i++) for (int j=0; j<M+5; j++)
            chk[i][j] = false;

        DFS(matrix, 0, 0, 0);

        return ret;
    }

    public boolean OOB(int x, int y) {
        return x<0 || x>=N || y<0 || y>=M;
    }

    public void DFS(int[][] matrix, int x, int y, int d) {
        chk[x][y] = true;
        ret.add(matrix[x][y]);

        int nx = x + dx[d], ny = y + dy[d];
        if (OOB(nx, ny) || chk[nx][ny]) {
            d = (d+1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }

        if (OOB(nx, ny) || chk[nx][ny]) return;

        DFS(matrix, nx, ny, d);
    }
}
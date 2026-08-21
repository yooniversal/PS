class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        
        int x = 0, y = 0, d = 0;
        int totalCells = n * n;
        
        for (int val = 1; val <= totalCells; val++) {
            matrix[x][y] = val;
            
            int nx = x + dx[d], ny = y + dy[d];
            
            if (OOB(nx, ny, n) || matrix[nx][ny] != 0) {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            
            x = nx;
            y = ny;
        }
        
        return matrix;
    }
    
    private boolean OOB(int x, int y, int n) {
        return x < 0 || x >= n || y < 0 || y >= n;
    }
}

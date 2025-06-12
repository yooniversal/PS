class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] origin = new int[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                origin[i][j] = matrix[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (origin[i][j] == 0) mask(matrix, i, j);
            }
        }
    }

    public void mask(int[][] matrix, int x, int y) {
        for (int i=0; i<matrix[0].length; i++) {
            matrix[x][i] = 0;
        }

        for (int i=0; i<matrix.length; i++) {
            matrix[i][y] = 0;
        }
    }
}
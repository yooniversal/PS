class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix[0].length;
        int[][] tempMatrix = new int[n][n];
        for (int i=0, a=n-1; i<n; i++, a--) {
            for (int j=0; j<n; j++) {
                tempMatrix[j][i] = matrix[a][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = tempMatrix[i][j];
            }
        }
    }
}
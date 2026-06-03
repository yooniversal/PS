class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] r : matrix) {
            for (int c : r) {
                if (target == c) return true;
            }
        }

        return false;
    }
}

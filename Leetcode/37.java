class Solution {
    static boolean[][] rowCheck = new boolean[9][10];
    static boolean[][] colCheck = new boolean[9][10];
    static boolean[][] blockCheck = new boolean[9][10];

    public void solveSudoku(char[][] board) {
        boolean success = false;
        
        init();

        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (board[x][y] != '.') {
                    int v = board[x][y] - '0';
                    rowCheck[x][v] = true;
                    colCheck[y][v] = true;
                    blockCheck[getBlock(x, y)][v] = true;
                }
            }
        }

        fillSudoku(board, 0, success);
    }

    void init() {
        for (int x = 0; x < 9; x++) {
            for (int y = 1; y < 10; y++) {
                rowCheck[x][y] = false;
                colCheck[x][y] = false;
                blockCheck[x][y] = false;
            }
        }
    }

    int getBlock(int x, int y) {
        return (x / 3) * 3 + (y / 3);
    }

    boolean canInsert(int x, int y, int v) {
        return !rowCheck[x][v] && !colCheck[y][v] && !blockCheck[getBlock(x, y)][v];
    }

    boolean fillSudoku(char[][] board, int current, boolean success) {
        if (success) return true;
        if (current >= 81) return true;

        int x = current / 9;
        int y = current % 9;

        if (board[x][y] != '.') {
            return fillSudoku(board, current + 1, success);
        }

        for (int v = 1; v <= 9; v++) {
            if (canInsert(x, y, v)) {
                rowCheck[x][v] = true;
                colCheck[y][v] = true;
                blockCheck[getBlock(x, y)][v] = true;
                board[x][y] = (char) ('0' + v);

                if (fillSudoku(board, current + 1, success)) return true;

                rowCheck[x][v] = false;
                colCheck[y][v] = false;
                blockCheck[getBlock(x, y)][v] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
}
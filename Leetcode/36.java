class Solution {

    static boolean success = false;
    static boolean[][] rowCheck = new boolean[9][10];
    static boolean[][] colCheck = new boolean[9][10];
    static boolean[][] blockCheck = new boolean[9][10];

    public boolean isValidSudoku(char[][] board) {

        for (int x=0; x<9; x++) {
            for (int y=1; y<10; y++) {
                rowCheck[x][y] = false;
                colCheck[x][y] = false;
                blockCheck[x][y] = false;
            }
        }

        for (int x=0; x<9; x++) {
            for (int y=0; y<9; y++) {
                int v = board[x][y] - '0';
                if (board[x][y] == '.') continue;
                if (!canInsert(x, y, v)) return false;

                rowCheck[x][v] = true;
                colCheck[y][v] = true;
                blockCheck[getBlock(x, y)][v] = true;
            }    
        }

        fillSudoku(board, 0);
        return success;
    }

    int getBlock(int x, int y) {
        if (x < 3) {
            if (y < 3) return 0;
            if (y < 6) return 1;
            return 2;
        }
        if (x < 6) {
            if (y < 3) return 3;
            if (y < 6) return 4;
            return 5;
        }
        if (y < 3) return 6;
        if (y < 6) return 7;
        return 8;
    }

    boolean canInsert(int x, int y, int v) {
        return !rowCheck[x][v] && !colCheck[y][v] && !blockCheck[getBlock(x, y)][v];
    }

    void fillSudoku(char[][] board, int current) {
        if (success) return;
        if (current >= 81) {
            success = true;
            return;
        }

        int x = current / 9;
        int y = current % 9;

        if (board[x][y] != '.') {
            fillSudoku(board, current + 1);
            return;
        }

        for (int v=1; v<=9; v++) {
            if (success) return;
            if (canInsert(x, y, v)) {
                rowCheck[x][v] = true;
                colCheck[y][v] = true;
                blockCheck[getBlock(x, y)][v] = true;

                fillSudoku(board, current + 1);

                rowCheck[x][v] = false;
                colCheck[y][v] = false;
                blockCheck[getBlock(x, y)][v] = false;
            }
        }
    }
}
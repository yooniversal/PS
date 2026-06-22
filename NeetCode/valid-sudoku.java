class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int r=0; r<9; r++) {
            Set<Character> set = new HashSet<>();
            for (int c=0; c<9; c++) {
                if (board[r][c] == '.') continue;
                if (set.contains(board[r][c])) return false;
                set.add(board[r][c]);
            }
        }

        for (int c=0; c<9; c++) {
            Set<Character> set = new HashSet<>();
            for (int r=0; r<9; r++) {
                if (board[r][c] == '.') continue;
                if (set.contains(board[r][c])) return false;
                set.add(board[r][c]);
            }
        }

        for (int r=0; r<9; r+=3) {
            for (int c=0; c<9; c+=3) {
                Set<Character> set = new HashSet<>();
                for (int dr=0; dr<3; dr++) {
                    for (int dc=0; dc<3; dc++) {
                        int curR=r+dr, curC=c+dc;
                        if (board[curR][curC] == '.') continue;
                        if (set.contains(board[curR][curC])) return false;
                        set.add(board[curR][curC]);
                    }
                }
            }
        }

        return true;
    }
}

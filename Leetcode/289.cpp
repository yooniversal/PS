class Solution {
public:
    int n, m;
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    bool OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }

    int getNumberByRules(int cur, int lives) {
        if (cur == 0) {
            if (lives == 3) return 1;
        } else {
            if (lives == 2 || lives == 3) return 1;
        }

        return 0;
    }    

    int getNextNumber(vector<vector<int>>& board, int x, int y) {
        int neighborCount = 0;

        for (int i=0; i<8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            neighborCount += board[nx][ny];
        }

        return getNumberByRules(board[x][y], neighborCount);
    }

    vector<vector<int>> BFS(vector<vector<int>>& board) {
        vector<vector<int>> ret;

        for (int i=0; i<n; i++) {
            vector<int> tmp;
            for (int j=0; j<m; j++) {
                tmp.push_back(getNextNumber(board, i, j));
            }
            ret.push_back(tmp);
        }

        return ret;
    }

    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(); m = board[0].size();
        board = BFS(board);
    }
};
class Solution {
public:
    struct S {
        vector<vector<int>> board;
        int x, y, cnt;
    };

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool OOB(int x, int y) {
        return x<0 || x>=2 || y<0 || y>=3;
    }

    bool isOk(vector<vector<int>>& board) {
        return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0;
    }

    vector<vector<int>> rotate(vector<vector<int>>& board, int x, int y, int nx, int ny) {
        vector<vector<int>> ret = board;

        int tmp = ret[x][y];
        ret[x][y] = ret[nx][ny];
        ret[nx][ny] = tmp;

        return ret;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int ret = 0;
        set<vector<vector<int>>> chk;
        queue<S> q;

        int x = -1, y = -1;
        for (int i=0; i<2; i++) {
            if (x != -1) break;
            for (int j=0; j<3; j++) {
                if (board[i][j] == 0) {
                    x = i; y = j;
                    break;
                }
            }
        }

        chk.insert(board);
        q.push({board, x, y, 0});

        while (!q.empty()) {
            S cur = q.front(); q.pop();
            vector<vector<int>> board = cur.board;
            int x = cur.x;
            int y = cur.y;
            int cnt = cur.cnt;

            if (isOk(board)) return cnt;

            for (int d=0; d<4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (OOB(nx, ny)) continue;
                vector<vector<int>> nextBoard = rotate(board, x, y, nx, ny);
                if (chk.find(nextBoard) != chk.end()) continue;
                chk.insert(nextBoard);
                q.push({ nextBoard, nx, ny, cur.cnt + 1 });
            }
        }

        return -1;
    }
};
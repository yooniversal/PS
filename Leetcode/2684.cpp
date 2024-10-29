class Solution {
public:
    struct S {
        int x, y, cnt;
    };

    int dx[3] = {-1, 0, 1};
    int dy[3] = {1, 1, 1};
    int N, M;
    bool chk[1005][1005];

    bool OOB(int x, int y) {
        return x<0 || x>=N || y<0 || y>=M;
    }

    int BFS(vector<vector<int>>& grid, int x, int y) {
        memset(chk, false, sizeof(chk));
        chk[x][y] = true;
        queue<S> q;
        q.push({x, y, 0});

        int ret = 0;

        while (!q.empty()) {
            S cur = q.front(); q.pop();
            int x = cur.x, y = cur.y, cnt = cur.cnt;
            ret = max(ret, cnt);
            
            for (int d=0; d<3; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (OOB(nx, ny)) continue;
                if (chk[nx][ny] || grid[x][y] >= grid[nx][ny]) continue;
                chk[nx][ny] = true;
                q.push({nx, ny, cnt + 1});
            }
        }
        
        return ret;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ret = 0;

        N = grid.size();
        M = grid[0].size();

        for (int i=0; i<N; i++) {
            ret = max(ret, BFS(grid, i, 0));
        }

        return ret;
    }
};
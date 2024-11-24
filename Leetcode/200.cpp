class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    vector<vector<char>> a;
    bool chk[305][305];

    bool OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }

    void dfs(int x, int y) {
        for (int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == '0') continue;
            chk[nx][ny] = true;
            dfs(nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        n = grid.size();
        m = grid[0].size();
        a = grid;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '0' || chk[i][j]) continue;
                chk[i][j] = true;
                dfs(i, j);
                ret++;
            }
        }

        return ret;
    }
};
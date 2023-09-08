#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, m;
int a[10][10];
bool chk[10][10];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

int bfs(vector<ii> walls, vector<ii> virus) {
    queue<ii> q;
    for(auto& v : virus) {
        q.push(v);
        chk[v.first][v.second] = true;
    }

    memset(chk, false, sizeof(chk));

    int map[10][10];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        map[i][j] = a[i][j];
    }

    for(auto& wall : walls) {
        map[wall.first][wall.second] = 1;
    }

    while(!q.empty()) {
        ii cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;

        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(OOB(nx, ny)) continue;
            if(chk[nx][ny] || map[nx][ny] == 1) continue;
            chk[nx][ny] = true;
            map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    int cnt = 0;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        if(map[i][j] == 0) ++cnt;
    }

    return cnt;
}

int main () {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<ii> virus;
    cin >> n >> m;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        cin >> a[i][j];
        if(a[i][j] == 2) {
            virus.push_back({i, j});
        }
    }

    int ret = 0;
    const int len = n * m;
    for(int i=0; i<len; ++i) {
        if(a[i/m][i%m] != 0) continue;
        for(int j=i+1; j<len; ++j) {
            if(a[j/m][j%m] != 0) continue;
            for(int k=j+1; k<len; ++k) {
                if(a[k/m][k%m] != 0) continue;
                vector<ii> walls;
                walls.push_back({i/m, i%m});
                walls.push_back({j/m, j%m});
                walls.push_back({k/m, k%m});
                ret = max(ret, bfs(walls, virus));
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
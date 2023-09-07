#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, m;
int a[1005][1005];
int ret[1005][1005];
bool chk[1005][1005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

class S {
    public:
    int x, y, cnt;
    S(int a, int b, int c){
        x = a;
        y = b;
        cnt = c;
    }
};

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

int main () {

    ii start = {-1, -1};
    cin >> n >> m;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        cin >> a[i][j];
        if(a[i][j] == 2) {
            start.first = i;
            start.second = j;
        }
    }

    queue<S> q;
    q.push(S(start.first, start.second, 0));
    ret[start.first][start.second] = 0;
    chk[start.first][start.second] = true;

    while(!q.empty()) {
        S cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, cnt = cur.cnt;
        
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(OOB(nx, ny)) continue;
            if(chk[nx][ny] || a[nx][ny] == 0) continue;
            chk[nx][ny] = true;
            ret[nx][ny] = cnt + 1;
            q.push(S(nx, ny, cnt + 1));
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i == start.first && j == start.second) continue;
            if(a[i][j] == 0) continue;
            if(ret[i][j] != 0) continue;
            ret[i][j] = -1;
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
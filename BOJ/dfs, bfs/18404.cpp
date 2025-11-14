#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

struct S {
    int x, y, cnt;
    S(int x, int y, int cnt): x(x), y(y), cnt(cnt) {}
};

int n, m;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int a[505][505];

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void initStep(int sx, int sy) {
    a[sx][sy] = 0;
    queue<S> q;
    q.push({sx, sy, 0});

    while (!q.empty()) {
        S cur = q.front(); q.pop();
        for (int i=0; i<8; i++) {
            int nx = cur.x+dx[i], ny = cur.y+dy[i];
            if (OOB(nx, ny) || a[nx][ny] != -1) continue;
            a[nx][ny] = cur.cnt+1;
            q.push(S(nx, ny, cur.cnt+1));
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;
    int sx, sy; cin >> sx >> sy;
    sx--; sy--;
    memset(a, -1, sizeof(a));

    initStep(sx, sy);

    while (m--) {
        int x, y; cin >> x >> y;
        x--; y--;
        cout << a[x][y] << " ";
    }
    cout << '\n';

    return 0;
}
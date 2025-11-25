#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

struct S {
    int x, y, cnt;
};

int a[505][505], cnt[505][505];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) {
    return x<0 || x>500 || y<0 || y>500;
}

int main() {
    FASTIO;

    for (int i=0; i<505; i++) for (int j=0; j<505; j++) cnt[i][j] = INF;

    int n; cin >> n;
    int x1, y1, x2, y2;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x=min(x1, x2); x<=max(x1, x2); x++) {
            for (int y=min(y1, y2); y<=max(y1, y2); y++) {
                a[x][y] = 1;
            }
        }
    }

    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x=min(x1, x2); x<=max(x1, x2); x++) {
            for (int y=min(y1, y2); y<=max(y1, y2); y++) {
                a[x][y] = 2;
            }
        }
    }

    queue<S> q;
    q.push({0, 0, 0});
    bool flag = true;
    while (!q.empty()) {
        S cur = q.front(); q.pop();

        if (cur.x == 500 && cur.y == 500) {
            flag = false;
        }
        
        for (int d=0; d<4; d++) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            int nCnt = cur.cnt + a[nx][ny];
            if (OOB(nx, ny) || a[nx][ny] == 2 || cnt[nx][ny] <= nCnt) continue;
            if (cnt[nx][ny] > 0) cnt[nx][ny] = min(cnt[nx][ny], nCnt);
            else cnt[nx][ny] = nCnt;
            q.push({nx, ny, nCnt});
        }
    }

    if (flag) {
        cout << -1 << '\n';
    } else {
        cout << cnt[500][500] << '\n';
    }

    return 0;
}
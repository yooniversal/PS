//1600
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
    int x, y, k, cnt;
};

int dhx[] = { -1,-2,-2,-1,1,2,2,1 }, dhy[] = { -2,-1,1,2,-2,-1,1,2 };
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,1,-1 };
int k, w, h;
int a[201][201];
bool chk[201][201][31];

bool OOB(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w) return true;
    return false;
}

int BFS() {
    queue<P> q;
    chk[0][0][k] = true;
    q.push({ 0, 0, k, 0 });
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, k = q.front().k, cnt = q.front().cnt; q.pop();
        if (x == h - 1 && y == w - 1) return cnt;
        if (k) {
            for (int i = 0; i < 8; ++i) {
                int nx = x + dhx[i], ny = y + dhy[i];
                if (OOB(nx, ny)) continue;
                if (a[nx][ny]) continue;
                if (chk[nx][ny][k-1]) continue;
                chk[nx][ny][k-1] = true;
                q.push({ nx, ny, k - 1, cnt + 1 });
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (a[nx][ny]) continue;
            if (chk[nx][ny][k]) continue;
            chk[nx][ny][k] = true;
            q.push({ nx, ny, k, cnt + 1 });
        }
    }
    return -1;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k >> w >> h;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];

    cout << BFS();

    return 0;
}
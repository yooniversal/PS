//14442
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
    int x, y, w, cnt;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, k;
int chk[1001][1001];
vector<string> MAP;

bool OOB(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

int BFS() {
    queue<P> q;
    q.push({ 0,0,1,1 });
    chk[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, w = q.front().w, cnt = q.front().cnt; q.pop();
        if (x == n - 1 && y == m - 1) return cnt;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (w == k && MAP[nx][ny] == '1') continue;
            if (chk[nx][ny]) {
                if (MAP[nx][ny] == '1' && chk[nx][ny] <= w + 1) continue;
                if (MAP[nx][ny] == '0' && chk[nx][ny] <= w) continue;
            }
            chk[nx][ny] = w;
            if (MAP[nx][ny] == '1') ++chk[nx][ny];
            q.push({ nx, ny, chk[nx][ny], cnt + 1 });
        }
    }
    return -1;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    ++k;
    MAP.resize(n);
    for (int i = 0; i < n; ++i) cin >> MAP[i];

    cout << BFS();

    return 0;
}
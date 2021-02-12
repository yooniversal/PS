//16933
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 9901;

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

        bool flag = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (MAP[nx][ny] == '1') {
                if (w == k) continue;
                if (cnt % 2 == 0) continue; //นใ
                if (chk[nx][ny] <= w + 1 && chk[nx][ny] != 0) continue;
            }
            if (MAP[nx][ny] == '0' && chk[nx][ny] <= w && chk[nx][ny] != 0) continue;
            if(MAP[nx][ny] == '1') flag = false;
            chk[nx][ny] = MAP[nx][ny] == '1' ? w+1 : w;
            q.push({ nx, ny, chk[nx][ny], cnt + 1 });
        }

        if (flag && cnt % 2 == 0) {
            q.push({x, y, chk[x][y], cnt + 1});
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

    cout << BFS() << '\n';

    return 0;
}
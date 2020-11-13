//3197
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
    int x, y, cnt;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;
vector<string> a;
int MAP[1501][1501];
bool chk[1501][1501];
ii start;

bool OOB(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

bool connectBFS(int wall) {
    memset(chk, 0, sizeof(chk));
    queue<ii> q;
    q.push({ start.first, start.second });
    chk[start.first][start.second] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if (a[x][y] == 'L' && x != start.first && y != start.second) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (chk[nx][ny]) continue;
            if (MAP[nx][ny] > wall) continue;
            chk[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
    return false;
}

void meltBFS() {
    queue<P> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') continue;
            q.push({ i, j, 0 });
        }
    }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
        if (chk[x][y]) continue;
        chk[x][y] = 1;
        MAP[x][y] = cnt;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (a[nx][ny] != 'X') continue;
            a[nx][ny] = '.';
            q.push({ nx, ny, cnt + 1 });
        }
    }
}

ll binary_search(ll l, ll r) {
    ll ret = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (!connectBFS(m))
            l = m + 1;
        else {
            r = m - 1;
            ret = m;
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        a.push_back(s);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'L') {
                start.first = i;
                start.second = j;
            }
        }
    }

    meltBFS();
    cout << binary_search(0, 1500);

    return 0;
}
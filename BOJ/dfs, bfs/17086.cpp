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
    int x, y, v;
};

int n, m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int d[55][55];
bool isShark[55][55];

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

int main() {
    FASTIO;

    cin >> n >> m;

    vii sharks;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int v; cin >> v;
            if (v == 1) {
                isShark[i][j] = true;
                sharks.push_back({i, j});
            }
        }
    }

    int ret = 0;

    queue<S> q;
    for (auto& s : sharks) q.push({s.first, s.second, 0});

    while (!q.empty()) {
        S cur = q.front(); q.pop();

        for (int i=0; i<8; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (OOB(nx, ny) || isShark[nx][ny] || d[nx][ny] > 0) continue;
            d[nx][ny] = cur.v + 1;
            ret = max(ret, d[nx][ny]);
            q.push({nx, ny, cur.v + 1});
        }
    }

    cout << ret << '\n';

    return 0;
}
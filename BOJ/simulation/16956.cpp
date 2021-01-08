//16956
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int n, m, dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
char a[501][501];
vii p;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (a[i][j] == 'W') p.push_back({ i,j });
    }

    bool install = true;
    for (auto& W : p) {
        int x = W.first, y = W.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (a[nx][ny] == 'S') {
                install = false;
            }
            else if (a[nx][ny] == '.') a[nx][ny] = 'D';
        }
    }

    if (install) {
        cout << 1 << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << a[i][j];
            cout << '\n';
        }
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
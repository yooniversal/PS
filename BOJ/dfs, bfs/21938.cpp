#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m, t;
int a[3][1005][1005], convertedColors[1005][1005];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
bool chk[1005][1005];

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

void DFS(int x, int y) {
    for (int d=0; d<4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (OOB(nx, ny) || chk[nx][ny] || convertedColors[nx][ny] != 255) continue;
        chk[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<3; k++) cin >> a[k][i][j];
    cin >> t;

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        convertedColors[i][j] = (a[0][i][j] + a[1][i][j] + a[2][i][j]) / 3 >= t ? 255 : 0;
    }

    int ret = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        if (chk[i][j] || convertedColors[i][j] != 255) continue;
        chk[i][j] = true;
        DFS(i, j);
        ret++;
    }

    cout << ret << '\n';

    return 0;
}
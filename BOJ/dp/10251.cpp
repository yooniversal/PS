//10251
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int dx[] = { 0,1 }, dy[] = { 1,0 };
int n, m, l, g;
int dp[105][105][205][2], r[105][105], c[105][105];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		for (int x = 0; x < 105; ++x) {
			for (int y = 0; y < 105; ++y) {
				r[x][y] = c[x][y] = INF;
				for (int k = 0; k < 205; ++k) {
					for (int d = 0; d < 2; ++d) {
						dp[x][y][k][d] = INF;
					}
				}
			}
		}
		cin >> n >> m >> l >> g;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m-1; ++j)
				cin >> c[i][j];
		for (int i = 0; i < n-1; ++i)
			for (int j = 0; j < m; ++j)
				cin >> r[i][j];
		
		dp[0][1][0][0] = c[0][0];
		dp[1][0][0][1] = r[0][0];
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				for (int k = 0; k < n+m; ++k) {
					for (int d = 0; d < 2; ++d) {
						if (dp[x][y][k][d] == INF) continue;
						for (int i = 0; i < 2; ++i) {
							int nx = x + dx[i], ny = y + dy[i];
							int nextk = i == d ? k : k + 1;
							if (OOB(nx, ny)) continue;
							if (i == 0) dp[nx][ny][nextk][i] = min(dp[nx][ny][nextk][i], dp[x][y][k][d] + c[x][y]);
							else dp[nx][ny][nextk][i] = min(dp[nx][ny][nextk][i], dp[x][y][k][d] + r[x][y]);
						}
					}
				}
			}
		}

		int ret = INF;
		for (int k = 0; k < 205; ++k)
			for (int d = 0; d < 2; ++d) {
				if (dp[n - 1][m - 1][k][d] > g) continue;
				ret = min(ret, (n + m - 2) * l + k);
			}
		if (ret == INF) cout << -1 << '\n';
		else cout << ret << '\n';
	}

	return 0;
}
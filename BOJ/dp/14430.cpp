//14430
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 987654321;

int dp[301][301];
int a[301][301];
int dx[] = { 0,1 }, dy[] = { 1,0 };

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (dp[i][j] == -1) continue;
		for (int d = 0; d < 2; ++d) {
			int nx = i + dx[d], ny = j + dy[d];
			if (nx<0||nx>=n||ny<0||ny>=m) continue;
			dp[nx][ny] = max(dp[nx][ny], dp[i][j] + a[nx][ny]);
		}
	}

	cout << dp[n - 1][m - 1] << '\n';

	return 0;
}
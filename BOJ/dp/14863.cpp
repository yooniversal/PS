//14863
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1000000007;

struct P {
	int wt, wm, bt, bm;
};

int dp[101][100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	int n, k; cin >> n >> k;
	vector<P> way(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> way[i].wt >> way[i].wm >> way[i].bt >> way[i].bm;
	}

	dp[0][k] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int t = 1; t <= k; ++t) {
			if (dp[i - 1][t] == -1) continue;
			if (t - way[i].wt >= 0) dp[i][t - way[i].wt] = max(dp[i][t - way[i].wt], dp[i - 1][t] + way[i].wm);
			if (t - way[i].bt >= 0) dp[i][t - way[i].bt] = max(dp[i][t - way[i].bt], dp[i - 1][t] + way[i].bm);
		}
	}

	int ret = 0;
	for (int i = 0; i <= k; ++i)
		ret = max(ret, dp[n][i]);
	cout << ret << '\n';

	return 0;
}
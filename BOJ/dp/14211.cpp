//14211
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[501][100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	int n, sum = 0; cin >> n;
	vi h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		sum += h[i];
	}

	dp[0][0] = 0;
	dp[0][h[0]] = h[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 100001; ++j) {
			if (dp[i - 1][j] == -1) continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j + h[i]] = max(dp[i][j + h[i]], dp[i - 1][j] + h[i]);
			if (h[i] <= j) dp[i][j - h[i]] = max(dp[i][j - h[i]], dp[i - 1][j]);
			else dp[i][h[i] - j] = max(dp[i][h[i] - j], dp[i - 1][j] + h[i] - j);
		}
	}

	cout << sum - dp[n - 1][0];

	return 0;
}
//17175
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 501, INF = 1000000001, MOD = 1000000007;

ll dp[51];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;
	cout << dp[n] << '\n';

	return 0;
}
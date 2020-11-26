//8394
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10000001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[MAX][2];
int n;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][1] = (dp[i][1] + dp[i - 1][0]) % 10;
		dp[i][0] = (dp[i][0] + dp[i - 1][0] + dp[i - 1][1]) % 10;
	}
	cout << (dp[n][0] + dp[n][1])%10 << '\n';

	return 0;
}
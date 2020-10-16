//9657
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	for (int i = 5; i <= n; ++i)
		dp[i] = !dp[i - 1] | !dp[i - 3] | !dp[i - 4];
	if (dp[n]) cout << "SK";
	else cout << "CY";

	return 0;
}
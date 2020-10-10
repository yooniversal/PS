//2502
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[31];
int d, k;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= 30; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	cin >> d >> k;
	int a, b;
	for (int i = 1; i <= k / 2+1; ++i) {
		a = i;
		if ((k - dp[d - 2] * a) % dp[d - 1]) continue;
		b = (k - dp[d - 2] * a) / dp[d - 1];
		cout << a << '\n' << b;
		return 0;
	}

	return 0;
}
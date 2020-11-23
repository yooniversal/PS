//2291
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[11][221][221];
int n, m, k;
int ret[11];

ll f(int n, int prev, int sum) {
	if (n == 0) return sum == 0;
	if (sum == 0) return 0;
	ll& ret = cache[n][prev][sum];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = prev; i <= sum; ++i) {
		ret += f(n - 1, i, sum - i);
	}
	return ret;
}

void solve(int n, int prev, int sum, int k, int p) {
	if (n == 0) return;
	for (int i = prev; i <= sum; ++i) {
		if (k <= f(n - 1, i, sum - i)) {
			ret[p] = i;
			solve(n - 1, i, sum - i, k, p + 1);
			break;
		}
		k -= f(n - 1, i, sum - i);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	solve(n, 1, m, k, 0);
	for (int i = 0; i < n; ++i) cout << ret[i] << ' ';

	return 0;
}
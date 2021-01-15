//16974
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

ll N, X, cache[51], cache2[51];

ll f(int n) {
	if (n <= 0) return 1;
	ll& ret = cache[n];
	if (ret != -1) return ret;
	ret = 2 * f(n - 1) + 3;
	return ret;
}

ll g(int n) {
	if (n <= 0) return 1;
	ll& ret = cache2[n];
	if (ret != -1) return ret;
	ret = 2 * g(n - 1) + 1;
	return ret;
}

ll solve(ll remain, ll size) {
	if (size <= 0) return 1;
	if (remain >= f(size) - 1) return g(size);
	if (remain >= f(size - 1) + 3) return g(size - 1) + 1 + solve(remain - f(size - 1) - 2, size - 1);
	if (remain == f(size - 1) + 2) return g(size - 1) + 1;
	if (remain >= 2) return solve(remain - 1, size-1);
	return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 51; ++i) cache[i] = cache2[i] = -1;
	cin >> N >> X;
	cout << solve(X, N) << '\n';

	return 0;
}
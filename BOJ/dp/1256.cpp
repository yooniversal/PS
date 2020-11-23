//1256
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[201][101];
ll n, m, k;
char ret[201];

//ÀÚ¸´¼ö, zÀÇ °¹¼ö
ll f(int n, int m) {
	if (n == m || m == 0) return 1;
	ll& ret = cache[n][m];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(n - 1, m);
	if (m > 0) ret += f(n - 1, m - 1);
	return ret;
}

void solve(int n, int m, ll k, int p) {
	if (n == m) {
		for (int i = 0; i < m; ++i)
			ret[p + i] = 'z';
		return;
	}
	if (m == 0) {
		for (int i = 0; i < n; ++i)
			ret[p + i] = 'a';
		return;
	}
	if (k <= f(n - 1, m)) {
		ret[p] = 'a';
		solve(n - 1, m, k, p + 1);
	}
	else {
		ret[p] = 'z';
		solve(n - 1, m - 1, k - f(n - 1, m), p + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	if (f(n + m, m) < k) cout << -1;
	else {
		solve(n + m, m, k, 0);
		for (int i = 0; i < n + m; ++i) cout << ret[i];
	}

	return 0;
}
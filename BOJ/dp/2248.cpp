//2248
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int W[35];
ll N, L, K;
ll cache[35][35];

ll f(int n, int m) {
	if (n == 0 || m == 0) return 1;
	ll& ret = cache[n][m];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(n - 1, m);
	if (m > 0) ret += f(n - 1, m - 1);
	return ret;
}

void solve(int n, int m, int k, int p) {
	if (n == 0) return;
	if (m == 0) {
		for (int i = p; i < N; ++i)
			W[i] = 0;
		return;
	}

	if (k < f(n - 1, m)) {
		W[p] = 0;
		solve(n - 1, m, k, p + 1);
	}
	else {
		W[p] = 1;
		solve(n - 1, m - 1, k - f(n - 1, m), p + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> N >> L >> K;
	solve(N, L, K-1, 0);
	for (int i = 0; i < N; ++i) cout << W[i];

	return 0;
}
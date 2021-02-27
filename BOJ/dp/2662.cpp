//2662
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int n, m;
int profit[21][301], cache[21][301], cost[21];

int f(int cur, int remain) {
	if (cur == m) return 0;
	int& ret = cache[cur][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= remain; ++i) {
		ret = max(ret, f(cur + 1, remain - i) + profit[cur][i]);
	}

	return ret;
}

void solve(int cur, int remain) {
	if (cur == m - 1) {
		cost[cur] = remain;
		return;
	}

	for (int i = 0; i <= remain; ++i) {
		if (f(cur+1, remain-i) + profit[cur][i] == f(cur, remain)) {
			cost[cur] = i;
			solve(cur + 1, remain - i);
			return;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int M; cin >> M;
		for (int j = 0; j < m; ++j) {
			cin >> profit[j][M];
		}
	}

	cout << f(0, n) << '\n';
	solve(0, n);
	for (int i = 0; i < m; ++i) {
		cout << cost[i] << ' ';
	}
	cout << '\n';

	return 0;
}
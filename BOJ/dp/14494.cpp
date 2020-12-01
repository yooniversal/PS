//14494
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int dx[] = { 0,1,1 }, dy[] = { 1,0,1 };
int n, m;
int cache[1001][1001];

bool OOB(int x, int y) { return x > n || y > m; }

int f(int x, int y) {
	if (x == n && y == m) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 3; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		ret = (ret + f(nx, ny)) % MOD;
	}
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	cout << f(1, 1) << '\n';

	return 0;
}
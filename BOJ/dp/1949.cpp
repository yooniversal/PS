//1949
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[10001][2];
vi adj[10001], a;
bool chk[10001];
int n;

int solve(int root, bool G) {
	int& ret = cache[root][G];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : adj[root]) {
		if (chk[next]) continue;
		chk[next] = true;
		if (G) ret += solve(next, 0);
		else ret += max(solve(next, 0), solve(next, 1) + a[next]);
		chk[next] = false;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	chk[1] = true;
	cout << max(solve(1, 0), solve(1, 1) + a[1]);

	return 0;
}
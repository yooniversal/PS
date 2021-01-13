//16964
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int n, rp=1;
vi adj[100001], ret;
bool chk[100001];

void DFS(int cur) {
	if (rp >= n) {
		cout << 1 << '\n';
		exit(0);
	}

	for (int i = 0; i < adj[cur].size(); ++i) {
		auto next = lower_bound(adj[cur].begin(), adj[cur].end(), ret[rp]);
		if (next == adj[cur].end() || *next != ret[rp]) break;
		if (chk[*next]) continue;
		chk[*next] = true;
		++rp;
		DFS(*next);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	ret.resize(n);
	for (int i = 0; i < n; ++i) cin >> ret[i];
	chk[1] = true;
	DFS(1);
	cout << 0 << '\n';

	return 0;
}
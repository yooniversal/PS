//15899
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m, c, cnt;
int color[MAX], match[MAX], bound[MAX];
bool chk[MAX];
vi adj[MAX];
vi tree[MAX * 4];

void update(int s, int e, int node, int idx, int val) {
	if (idx < s || e < idx) return;
	int m = (s + e) / 2;
	tree[node].push_back(val);
	if (s != e) {
		update(s, m, 2 * node, idx, val);
		update(m + 1, e, 2 * node + 1, idx, val);
	}
}

int query(int s, int e, int node, int l, int r, int val) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return (upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin()) % MOD;
	int m = (s + e) / 2;
	int left = query(s, m, 2 * node, l, r, val) % MOD;
	int right = query(m + 1, e, 2 * node + 1, l, r, val) % MOD;
	return (left + right) % MOD;
}

void order(int root) {
	int now = ++cnt;
	match[root] = now;
	for (auto& next : adj[root]) {
		if (chk[next]) continue;
		chk[next] = true;
		order(next);
	}
	bound[now] = cnt;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> c;
	for (int i = 1; i <= n; ++i) cin >> color[i];
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	chk[1] = true;
	order(1); //DFS로 돌면서 번호 재설정 및 구간 설정

	for (int i = 1; i <= n; ++i)
		update(1, MAX - 1, 1, match[i], color[i]);

	for (int i = 1; i < MAX * 4; ++i)
		sort(tree[i].begin(), tree[i].end());

	ll ret = 0;
	while (m--) {
		int i, j; cin >> i >> j;
		int now = match[i];
		ret += query(1, MAX - 1, 1, now, bound[now], j) % MOD;
		ret %= MOD;
	}
	cout << ret;

	return 0;
}
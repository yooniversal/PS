//6118
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct S {
	int x, y, cnt;
};

int n, m, max_dist;
int a[20005];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[20005];
vi adj[20005];

void BFS() {
	
	queue<ii> q;
	q.push({ 1, 0 });
	chk[1] = true;
	while (!q.empty()) {
		
		auto cur = q.front(); q.pop();
		max_dist = max(max_dist, cur.second);
		
		for (auto& next : adj[cur.first]) {
			if (chk[next]) continue;
			chk[next] = true;
			a[next] = cur.second + 1;
			q.push({ next , cur.second + 1 });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	BFS();

	int ret = INF, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (max_dist == a[i]) {
			++cnt;
			ret = min(ret, i);
		}
	}

	cout << ret << " " << max_dist << " " << cnt << '\n';

	return 0;
}
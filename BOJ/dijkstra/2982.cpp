//2982
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 100000;

int dist[MAX], road[MAX][MAX];
bool chk[MAX];
ii used[MAX][MAX];
vii adj[MAX];

void dijkstra(int start, int add) {
	fill(dist, dist + MAX, INF);
	dist[start] = add;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({ add, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto& next : adj[cur]) {
			int nextDist = distance + next.second;
			int l = used[cur][next.first].first, r = used[cur][next.first].second;
			if (l <= distance && distance <= r) nextDist += (r + 1) - distance;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) road[i][j] = INF;

	int n, m; cin >> n >> m;
	int a, b, k, g; cin >> a >> b >> k >> g;
	vi route(g);
	for (int i = 0; i < g; ++i) cin >> route[i];
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
		road[u][v] = min(road[u][v], w);
		road[v][u] = min(road[v][u], w);
	}
	int cur = 0;
	for (int i = 0; i < g - 1; ++i) {
		used[route[i]][route[i + 1]] = used[route[i + 1]][route[i]] = { cur, cur + road[route[i]][route[i + 1]]-1 };
		cur += road[route[i]][route[i + 1]];
	}

	dijkstra(a, k);
	cout << dist[b] - k << '\n';

	return 0;
}
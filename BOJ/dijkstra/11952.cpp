//11952
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int n, m, k, s, p, q;
ll warn[MAX], dist[MAX];
bool infected[MAX], chk[MAX];
queue<pair<ll, ll>> Q;
vi adj[MAX];
vector<pair<ll, ll>> a[MAX];

void BFS() {
	while (!Q.empty()) {
		int cur = Q.front().first, cnt = Q.front().second; Q.pop();
		if (cnt < 0 || warn[cur] >= cnt) continue;
		warn[cur] = cnt;
		for (int next : adj[cur]) {
			Q.push({ next, cnt - 1 });
		}
	}
}

void dijkstra(int start) {
	fill(dist, dist + MAX, LLONG_MAX);
	dist[start] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		ll cur = pq.top().second, distance = -pq.top().first; pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			ll nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k >> s >> p >> q;
	for (int i = 0; i < k; ++i) {
		int x; cin >> x;
		Q.push({ x,s });
		infected[x] = true;
	}
	vii E;
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		E.push_back({ u,v });
	}
	fill(warn, warn + MAX, -1);
	BFS();

	for (int i = 0; i < m; ++i) {
		int u = E[i].first, v = E[i].second;
		if (infected[u] || infected[v]) continue;
		if (v != n) a[u].push_back({ v, warn[v] == -1 ? p : q });
		else a[u].push_back({ v, 0 });
		if (u != n) a[v].push_back({ u, warn[u] == -1 ? p : q });
		else a[v].push_back({ u, 0 });
	}
	dijkstra(1);
	cout << dist[n] << '\n';

	return 0;
}
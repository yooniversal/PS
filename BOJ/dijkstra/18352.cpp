//18352
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 300001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX];
bool chk[MAX];
vii node[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	dist[start] = 0;
	priority_queue <ii, vii, greater<ii>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second, distance = pq.top().first; pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (distance > dist[cur]) continue;
		for (auto& next : node[cur]) {
			int nextDist = dist[cur] + next.second;
			if (dist[next.first] > nextDist) {
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

	int n, m, k, x; cin >> n >> m >> k >> x;
	while (m--) {
		int u, v; cin >> u >> v;
		node[u].push_back({ v, 1 });
	}

	dijkstra(x);

	vi ret;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == k) {
			ret.push_back(i);
		}
	}
	sort(ret.begin(), ret.end());
	if (ret.size()) for (int r : ret) cout << r << '\n';
	else cout << -1 << '\n';

	return 0;
}
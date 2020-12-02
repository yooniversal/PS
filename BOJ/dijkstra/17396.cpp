//17396
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const ll MAX = 100001, INF = 30000000001, MOD = 1000000007;

ll dist[MAX];
bool chk[MAX], ban[MAX];
vector<pair<ll, ll>> a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	dist[start] = 0;
	priority_queue<pair<ll, int>> pq; //가까운 순서대로 처리하기 위함
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		//최단거리가 아님
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

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> ban[i];
	ban[n-1] = 0;
	
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		if (ban[u] || ban[v]) continue;
		a[u].push_back({ v, w });
		a[v].push_back({ u, w });
	}

	dijkstra(0);

	if (dist[n - 1] == INF) cout << -1 << '\n';
	else cout << dist[n - 1] << '\n';

	return 0;
}
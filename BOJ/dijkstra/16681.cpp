//16681
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const ll INF = 1000000000001;

ll h[MAX], dist[2][MAX];
vector<pair<int, ll>> a[MAX];

void dijkstra(int start) {
	int now = start == 1 ? 0 : 1;
	for (int i = 0; i < MAX; ++i) dist[now][i] = INF;
	dist[now][start] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll distance = -pq.top().first;
		pq.pop();

		if (dist[now][cur] < distance) continue;
		for (auto& next : a[cur]) {
			ll nextDist = distance + next.second;
			if (nextDist < dist[now][next.first]) {
				dist[now][next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}


int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, D, E; cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; ++i) cin >> h[i];
	while (M--) {
		int u, v, w; cin >> u >> v >> w;
		if(h[u] < h[v]) a[u].push_back({ v, w });
		else if(h[u] > h[v]) a[v].push_back({ u, w });
	}

	dijkstra(1);
	dijkstra(N);
	
	ll ret = -INF;
	bool flag = false;
	for (int target = 2; target <= N - 1; ++target) {
		if (h[target] > 1 && dist[0][target] != INF && dist[1][target] != INF) {
			ret = max(ret, h[target] * E - (dist[0][target] + dist[1][target]) * D);
			flag = true;
		}
	}
	if (flag) cout << ret << '\n';
	else cout << "Impossible\n";

	return 0;
}
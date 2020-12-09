//1800
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

struct P {
	int cur, distance, remain;
};

struct cmp {
	bool operator()(P& a, P& b) {
		return a.distance > b.distance;
	}
};

int dist[MAX][MAX];
int n, p, k;
vii a[MAX];

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dist[i][j] = INF;
	for (int i = 0; i < MAX; ++i) dist[start][i] = 0;
	priority_queue<P, vector<P>, cmp> pq;
	pq.push({ start, 0, k });
	while (!pq.empty()) {
		int cur = pq.top().cur, distance = pq.top().distance, remain = pq.top().remain; pq.pop();
		if (dist[cur][remain] < distance) continue;
		for (auto& next : a[cur]) {
			if (remain > 0 && dist[next.first][remain-1] > distance) {
				dist[next.first][remain - 1] = distance;
				pq.push({ next.first, distance, remain - 1 });
			}
			int nextDist = max(distance, next.second);
			if (dist[next.first][remain] > nextDist) {
				dist[next.first][remain] = nextDist;
				pq.push({ next.first, nextDist, remain });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> p >> k;
	while (p--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}

	dijkstra(1);

	int ret = INF;
	for (int i = 0; i <= k; ++i)
		ret = min(ret, dist[n][i]);

	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}
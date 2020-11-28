//1446
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct R {
	int u, v, w;
};

int dist[MAX];
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	dist[start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
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

	int n, d; cin >> n >> d;
	vector<R> route;
	for (int i = 0; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		if (v > d || v - u < w) continue;
		route.push_back({ u,v,w });
		a[u].push_back({ v, w });
	}
	a[0].push_back({ d, d });

	for (int i = 0; i < route.size(); ++i) {
		if (0 < route[i].u) a[0].push_back({ route[i].u, route[i].u });
		if(route[i].v < d) a[route[i].v].push_back({ d, d-route[i].v });
		for (int j = 0; j < route.size(); ++j) {
			if (i == j) continue;
			if(route[i].v < route[j].u) a[route[i].v].push_back({ route[j].u, route[j].u-route[i].v });
			else if(route[i].v > route[j].u) a[route[j].u].push_back({ route[i].v, route[i].v-route[j].u });
		}
	}

	dijkstra(0);

	cout << dist[d] << '\n';

	return 0;
}
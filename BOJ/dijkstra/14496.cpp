//14496
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX];
int n, m;
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	memset(chk, 0, sizeof(chk));
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

	int s, e; cin >> s >> e >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		a[u].push_back({ v, 1 });
		a[v].push_back({ u, 1 });
	}
	dijkstra(s);
	if (dist[e] != INF) cout << dist[e] << '\n';
	else cout << -1 << '\n';

	return 0;
}
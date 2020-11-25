//10282
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
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
	memset(chk, 0, sizeof(chk));

	priority_queue<ii, vii, greater<ii>> q;
	dist[start] = 0;
	q.push({ 0, start });
	while (!q.empty()) {
		int cur = q.top().second, distance = q.top().first; q.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto next : node[cur]) {
			int v = next.first, nextDist = distance + next.second;
			if (dist[v] > nextDist) {
				dist[v] = nextDist;
				q.push({ nextDist, v });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < MAX; ++i) node[i].clear();

		int n, d, c; cin >> n >> d >> c;
		while (d--) {
			int u, v, w; cin >> u >> v >> w;
			node[v].push_back({ u, w });
		}
		dijkstra(c);
		int cnt = 0, fulltime = 0;
		for (int i = 1; i <= n; ++i) {
			//printf("dist[%d]:%d\n", i, dist[i]);
			if (dist[i] == INF) continue;
			fulltime = max(fulltime, dist[i]);
			++cnt;
		}
		cout << cnt << ' ' << fulltime << '\n';
	}

	return 0;
}
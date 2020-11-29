//1719
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 201
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX], route[MAX];
int n, m;
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= n; ++i) route[i] = i;
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
				route[next.first] = cur;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int from(int cur, int start) {
	int ret = 0;
	for (int i = cur; i != start; i = route[i]) {
		ret = i;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}

	vvi ret(n+1, vi(n+1, 0));
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
		for (int j = 1; j <= n; ++j) {
			ret[i][j] = from(j, i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) cout << "- ";
			else cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
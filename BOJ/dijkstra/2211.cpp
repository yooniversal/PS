//2211
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX], route[MAX];
int n;
bool visited[MAX];
vii a[MAX];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				route[next.first] = cur;
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

	fill(dist, dist + MAX, INF);
	int n, m; cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v, w });
		a[v].push_back({ u, w });
	}

	dijkstra(1);

	cout << n - 1 << '\n';
	for (int i = 2; i <= n; ++i)
		cout << i << ' ' << route[i] << '\n';

	return 0;
}
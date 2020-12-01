//2307
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1000000007;

int dist[MAX], route[MAX], bu=-1, bv=-1;
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	memset(chk, 0, sizeof(chk));
	fill(dist, dist + MAX, INF);
	dist[start] = 0;
	priority_queue<ii> pq; //가까운 순서대로 처리하기 위함
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		//최단거리가 아님
		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			if ((cur == bu && next.first == bv) || (cur == bv && next.first == bu)) continue;
			int nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				route[next.first] = cur;
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
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}

	dijkstra(1);
	int shortest = dist[n];
	vi R;
	for (int i = n; i != 0; i=route[i]) {
		R.push_back(i);
	}

	int ret = -1;
	for (int i = 0; i < R.size() - 1; ++i) {
		bu = R[i], bv = R[i + 1];
		dijkstra(1);
		if (dist[n] == INF) {
			cout << -1 << '\n';
			return 0;
		}
		ret = max(ret, dist[n] - shortest);
	}
	cout << ret << '\n';

	return 0;
}
//18223
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5001, INF = 1000000001, MOD = 1234567;

int dist[MAX];
int v, e, p;
bool chk[MAX];
vii a[MAX];

void dijkstra(int start, bool pass) {
	for (int i = 0; i < MAX; ++i) {
		dist[i] = INF;
		chk[i] = 0;
	}
	dist[start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (pass) if (cur == p) continue;
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

	cin >> v >> e >> p;
	while (e--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}

	dijkstra(1, true);
	int masan = dist[v], gunwoo = dist[p];

	dijkstra(p, false);
	if (gunwoo + dist[v] <= masan) cout << "SAVE HIM\n";
	else cout << "GOOD BYE\n";

	return 0;
}
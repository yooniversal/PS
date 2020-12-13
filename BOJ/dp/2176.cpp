//2176
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

ll dist[MAX], cache[MAX];
bool chk[MAX];
vector<pair<ll, ll>> a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, LLONG_MAX);
	dist[start] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		ll cur = pq.top().second;
		ll distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

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

ll f(int cur) {
	if (cur == 2) return 1;
	ll& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : a[cur]) {
		if (dist[cur] <= dist[next.first]) continue;
		ret += f(next.first);
	}
	return ret;
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
	dijkstra(2);

	memset(cache, -1, sizeof(cache));
	cout << f(1) << '\n';

	return 0;
}
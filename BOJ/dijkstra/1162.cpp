//1162
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

struct E {
	int u, k;
	ll d;
	E(int a, int b, ll c) : u(a), k(b), d(c) {}
};

struct cmp {
	bool operator()(E& a, E& b) {
		return a.d > b.d;
	}
};

ll dist[MAX][21];
vector<E> node[MAX];
int n, m, k;

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i) for (int j = 0; j < 21; ++j) dist[i][j] = 10000000000000LL;
	dist[start][k] = 0;
	priority_queue <E, vector<E>, cmp> pq;
	pq.push({ start, k, 0 });
	while (!pq.empty()) {
		int cur = pq.top().u, chance = pq.top().k;
		ll curDist = pq.top().d; pq.pop();
		if (curDist > dist[cur][chance]) continue;
		for (auto& next : node[cur]) {
			int to = next.u;
			if (chance>0 && dist[to][chance-1] > curDist) {
				dist[to][chance-1] = curDist;
				pq.push(E(to, chance-1, curDist));
			}
			if (dist[to][chance] > curDist + next.d) {
				dist[to][chance] = curDist + next.d;
				pq.push(E(to, chance, curDist + next.d));
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	while (m--) {
		int u, v; ll w; cin >> u >> v >> w;
		node[u].push_back(E(v, k, w));
		node[v].push_back(E(u, k, w));
	}
	dijkstra(1);
	ll ret = 10000000000000LL;
	for (int i = 0; i <= k; ++i) ret = min(ret, dist[n][i]);
	cout << ret << '\n';

	return 0;
}
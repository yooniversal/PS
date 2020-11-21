//16475
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

struct P {
	int u, w, cnt;
};

struct cmp {
	bool operator()(P& a, P& b) {
		return a.w > b.w;
	}
};

struct E {
	int v, w;
	bool trap, reverse;
};

int dist[MAX][21];
int n, m, k, l, p;
bool chk[MAX], trap[MAX];
vector<E> a[MAX];

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i) for (int j = 0; j < 21; ++j) dist[i][j] = INF;
	dist[start][0] = 0;
	priority_queue<P, vector<P>, cmp> pq;
	pq.push({ start, 0, 0 });
	while (!pq.empty()) {
		int cur = pq.top().u, distance = pq.top().w, cnt = pq.top().cnt; pq.pop();
		if (dist[cur][cnt] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.w, nextCnt = cnt + trap[next.v];
			if (nextCnt == 2 * p) nextCnt = 0;
			if (next.trap) {
				if (cnt >= p) {
					if (!next.reverse) nextDist = INF;
				}
				else if(next.reverse) nextDist = INF;
			}
			if (dist[next.v][nextCnt] > nextDist) {
				dist[next.v][nextCnt] = nextDist;
				pq.push({ next.v, nextDist, nextCnt });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k >> l >> p;
	while (k--) {
		int x; cin >> x;
		trap[x] = true;
	}
	m -= l;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v, w, false, false });
	}
	while (l--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v, w, true, false });
		a[v].push_back({ u, w, true, true });
	}

	int st, ed; cin >> st >> ed;
	dijkstra(st);

	int ret = INF;
	for (int i = 0; i <= 2*p; ++i) ret = min(ret, dist[ed][i]);
	if (ret != INF) cout << ret;
	else cout << -1;

	return 0;
}
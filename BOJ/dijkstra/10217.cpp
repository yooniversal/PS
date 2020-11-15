//10217
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct T {
	int cur, c, d;
};

struct cmp {
	bool operator()(T& a, T& b) {
		return a.d > b.d;
	}
};

int n, m, k;
int dist[101][10001];
bool chk[101][10001];
vector<T> ticket[101];

void dijkstra(int start) {
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 10001; ++j)
			dist[i][j] = INF;

	dist[start][m] = 0;
	priority_queue<T, vector<T>, cmp> pq;
	pq.push({ start, m, 0 });
	while (!pq.empty()) {
		int cur = pq.top().cur, c = pq.top().c, d = pq.top().d; pq.pop();
		if (dist[cur][c] < d) continue;
		for (auto& next : ticket[cur]){
			int nextDist = d + next.d;
			if (c - next.c < 0) continue;
			if (nextDist < dist[next.cur][c-next.c] || !chk[next.cur][c - next.c]) {
				chk[next.cur][c - next.c] = true;
				dist[next.cur][c-next.c] = nextDist;
				pq.push({ next.cur, c-next.c, nextDist });
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
		for (int i = 0; i < 101; ++i) ticket[i].clear();
		cin >> n >> m >> k;
		while (k--) {
			int u, v, c, d; cin >> u >> v >> c >> d;
			ticket[u].push_back({ v, c, d });
		}
		dijkstra(1);
		int ret = INF;
		for (int i = 0; i <= m; ++i) {
			if (!chk[n][i]) continue;
			ret = min(ret, dist[n][i]);
		}
		if (ret == INF) cout << "Poor KCM" << '\n';
		else cout << ret << '\n';
	}

	return 0;
}
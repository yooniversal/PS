//2311
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

int START = 1, END = -1, OUT = 1000;
int ret;
int cap[MAX][MAX], flo[MAX][MAX], from[MAX], cost[MAX][MAX], dist[MAX];
bool inQueue[MAX];
vi node[MAX];

void MCMF() {
	while (1) {
		fill(from, from + MAX, -1);
		fill(dist, dist + MAX, INF);
		fill(inQueue, inQueue + MAX, 0);
		queue<int> q;
		dist[START] = 0;
		inQueue[START] = true;
		q.push(START);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			inQueue[cur] = false;
			for (auto& next : node[cur]) {
				if (cap[cur][next] - flo[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
					dist[next] = dist[cur] + cost[cur][next];
					from[next] = cur;
					q.push(next);
					if (!inQueue[next]) {
						q.push(next);
						inQueue[next] = true;
					}
				}
			}
		}

		if (from[END] == -1) break;

		int flow = INF;
		for (int i = END; i != START; i = from[i]) {
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);
		}

		for (int i = END; i != START; i = from[i]) {
			ret += flow * cost[from[i]][i];
			flo[from[i]][i] += flow;
			flo[i][from[i]] -= flow;
		}
	}
}

void add(int u, int v, int c, int cc) {
	node[u].push_back(v);
	node[v].push_back(u);
	cap[u][v] = c;
	cost[u][v] = cc;
	cost[v][u] = -cc;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	START = 1; END = n + OUT;

	for (int i = 1; i <= n; ++i) {
		add(i, i + OUT, 2, 0);
	}

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		add(a + OUT, b, 1, c);
		add(b + OUT, a, 1, c);
	}

	MCMF();
	cout << ret;

	return 0;
}
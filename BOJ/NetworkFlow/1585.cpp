//1585
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 105
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 100 + 1, END = 100 + 2, OUT = 50;
int cap[MAX][MAX], flo[MAX][MAX], cost[MAX][MAX], dist[MAX], from[MAX];
bool inQueue[MAX];
vi node[MAX];

//간선
void add(int u, int v, int c, int cc) {
	node[u].push_back(v);
	node[v].push_back(u);
	cap[u][v] = c;
	cost[u][v] = cc;
	cost[v][u] = -cc;
}

int MCMF() {
	int ret = 0;
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
		for (int i = END; i != START; i = from[i])
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);

		for (int i = END; i != START; i = from[i]) {
			ret += flow * cost[from[i]][i];
			flo[from[i]][i] += flow;
			flo[i][from[i]] -= flow;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vi start(n), end(n);
	for (int i = 0; i < n; ++i) {
		cin >> start[i];
		add(START, i, 1, 0); //START -> 시작점
	}
	for (int i = 0; i < n; ++i) {
		cin >> end[i];
		add(i + OUT, END, 1, 0); //도착점 -> END
	}
	int T, F; cin >> T >> F;
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	for (int i = 0; i < n; ++i) {
		if (start[i] >= end[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}

	//시작점 -> 도착점
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (start[i] >= end[j]) continue;
			int M = max(0, T - (end[j] - start[i]));
			add(i, j + OUT, 1, min(F, M*M));
		}
	}

	cout << MCMF() << ' ';

	//최대 비용으로 초기화
	for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) {
		flo[i][j] = 0;
		cost[i][j] = -cost[i][j];
	}

	cout << -MCMF() << '\n';

	return 0;
}
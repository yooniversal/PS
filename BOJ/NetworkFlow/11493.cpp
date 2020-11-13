//11493
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 1000 + 1, END = 1000 + 2, IN = 500;
int ret;
int cap[MAX][MAX], flo[MAX][MAX], from[MAX], cost[MAX][MAX], dist[MAX], MINR[MAX][MAX];
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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ret = 0;
		for (int i = 0; i < MAX; ++i) {
			node[i].clear();
			for (int j = 0; j < MAX; ++j) {
				cap[i][j] = flo[i][j] = cost[i][j] = 0;
				MINR[i][j] = i==j ? 0 : INF;
			}
		}

		vi link[501];
		bool isblack[501] = { 0 };
		int n, m; cin >> n >> m;
		while(m--) {
			int a, b; cin >> a >> b;
			link[a].push_back(b);
			link[b].push_back(a);
			MINR[a][b] = MINR[b][a] = 1;
		}

		//플로이드로 최단 거리 구하기
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (MINR[i][j] > MINR[i][k] + MINR[k][j])
						MINR[i][j] = MINR[i][k] + MINR[k][j];

		for (int i = 1; i <= n; ++i) {
			cin >> isblack[i];
			if (isblack[i]) {
				//검은 정점 -> END
				node[IN +i].push_back(END);
				node[END].push_back(IN +i);
				cap[IN +i][END] = 1;
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			int coin; cin >> coin;
			if (coin) {
				//START -> 검은 동전
				node[START].push_back(i);
				node[i].push_back(START);
				cap[START][i] = 1;
				//검은 동전 -> 검은 정점
				for (int next = 1; next <= n; ++next) {
					if (i == next) continue;
					if (isblack[next]) {
						node[i].push_back(IN + next);
						node[IN + next].push_back(i);
						cap[i][IN + next] = 1;
						cost[i][IN + next] = MINR[i][next];
						cost[IN + next][i] = -MINR[i][next];
					}
				}
				//검은 정점 & 검은 동전
				//검은 동전으로 흘러가지 못하게 막는다
				if (isblack[i]) {
					flo[START][i] = flo[IN +i][END] = 1;
				}
			}
		}

		MCMF();
		cout << ret << '\n';
	}

	return 0;
}
//3640
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int OUT = 1000, START = 1000+1, END = 1000+2;		
int v, e;
int ret;
int cap[MAX][MAX], flo[MAX][MAX], from[MAX], cost[MAX][MAX], dist[MAX];
bool inQueue[MAX];
vi node[MAX];

void MCMF() {
	while (1) {
		memset(from, -1, sizeof(from));
		memset(inQueue, 0, sizeof(inQueue));
		fill(dist, dist + MAX, INF);
		queue<int> q;
		dist[1] = 0;
		inQueue[1] = true;
		q.push(1);
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

		if (from[v+OUT] == -1) break;

		int flow = INF;
		for (int i = v+OUT; i != 1; i = from[i])
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);

		for (int i = v+OUT; i != 1; i = from[i]) {
			ret += flow * cost[from[i]][i];
			flo[from[i]][i] += flow;
			flo[i][from[i]] -= flow;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	while (scanf("%d %d", &v, &e) > 0) {
		memset(cap, 0, sizeof(cap));
		memset(flo, 0, sizeof(flo));
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < MAX; ++i) node[i].clear();
		ret = 0;

		node[START].push_back(1);
		node[1].push_back(START);
		cap[START][1] = 1;
		
		for (int i = 1; i <= v; ++i) {
			node[i].push_back(i + OUT);
			node[i + OUT].push_back(i);
			if (i == 1 || i == v) cap[i][i + OUT] = 2;
			else cap[i][i + OUT] = 1;
		}

		while (e--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			node[a+OUT].push_back(b);
			node[b].push_back(a+OUT);
			cap[a+OUT][b] = 1;
			cost[a+OUT][b] = c;
			cost[b][a+OUT] = -c;
		}
		MCMF();
		flo[START][1] = 0;
		MCMF();
		cout << ret << '\n';
	}

	return 0;
}
//11405
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 200 + 1, END = 200 + 2;
int ret;
int cap[301][301], flo[301][301], from[301], cost[301][301], dist[301];
bool inQueue[301];
vi node[301];

void MCMF() {
	while (1) {
		fill(from, from + 301, -1);
		fill(dist, dist + 301, INF);
		fill(inQueue, inQueue + 301, 0);
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
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	//사람 -> END
	for (int person = 100 + 1; person <= 100 + n; ++person) {
		cin >> cap[person][END];
		node[person].push_back(END);
		node[END].push_back(person);
	}

	//START -> 서점
	for (int store = 1; store <= m; ++store) {
		cin >> cap[START][store];
		node[START].push_back(store);
		node[store].push_back(START);
	}

	//서점 -> 사람
	for (int store = 1; store <= m; ++store) {
		for (int person = 100 + 1; person <= 100 + n; ++person) {
			cin >> cost[store][person];
			cost[person][store] = -cost[store][person];
			cap[store][person] = INF;
			node[store].push_back(person);
			node[person].push_back(store);
		}
	}

	MCMF();
	cout << ret;

	return 0;
}
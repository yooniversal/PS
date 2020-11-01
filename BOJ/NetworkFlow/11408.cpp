//11408
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

const int START = 800 + 1, END = 800 + 2;
int ret, FLOW;
int cap[805][805], flo[805][805], from[805], cost[805][805], dist[805];
bool inQueue[805];
vi node[805];

void MCMF() {
	while (1) {
		fill(from, from + 805, -1);
		fill(dist, dist + 805, INF);
		fill(inQueue, inQueue + 805, 0);
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

		FLOW += flow;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	//START -> 사람
	for (int person = 1; person <= n; ++person) {
		cap[START][person] = 1;
		node[START].push_back(person);
		node[person].push_back(START);
	}

	//일 -> END
	for (int work = 400+1; work <= 400+m; ++work) {
		cap[work][END] = 1;
		node[work].push_back(END);
		node[END].push_back(work);
	}

	//사람 -> 일
	for (int person = 1; person <= n; ++person) {
		int cnt; cin >> cnt;
		while (cnt--) {
			int work, COST; cin >> work >> COST;
			work += 400;
			cost[person][work] = COST;
			cost[work][person] = -COST;
			node[person].push_back(work);
			node[work].push_back(person);
			cap[person][work] = 1;
		}
	}

	MCMF();
	cout << FLOW << '\n' << ret;

	return 0;
}
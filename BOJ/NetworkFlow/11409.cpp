//11409
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 805
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 800 + 1, END = 800 + 2;
int ret2, ret;
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
		for (int i = END; i != START; i = from[i])
			flow = min(flow, cap[from[i]][i] - flo[from[i]][i]);

		ret += flow;
		for (int i = END; i != START; i = from[i]) {
			ret2 += flow * cost[from[i]][i];
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
	for (int person = 1; person <= n; ++person) {
		node[START].push_back(person);
		node[person].push_back(START);
		cap[START][person] = 1;
		int can; cin >> can;
		for (int i = 0; i < can; ++i) {
			int work, price; cin >> work >> price;
			work += 400;
			node[person].push_back(work);
			node[work].push_back(person);
			cap[person][work] = 1;
			cost[person][work] = -price;
			cost[work][person] = price;
		}
	}

	for (int work = 400+1; work <= 400+m; ++work) {
		node[work].push_back(END);
		node[END].push_back(work);
		cap[work][END] = 1;
	}

	MCMF();
	cout << ret << '\n' << -ret2;

	return 0;
}
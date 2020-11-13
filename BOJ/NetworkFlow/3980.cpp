//3980
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 150
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

const int START = 145 + 1, END = 145 + 2, P = 132;
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
			}
		}

		//START -> 포지션
		for (int i = 1; i <= 11; ++i) {
			node[START].push_back(i);
			node[i].push_back(START);
			cap[START][i] = 1;
		}

		vvi stat(12, vi(12));
		for (int i = 1; i <= 11; ++i) {
			for (int j = 1; j <= 11; ++j) {
				cin >> stat[i][j];
			}
		}

		/*for (int i = 1; i <= 11; ++i) {
			for (int j = 1; j <= 11; ++j) {
				printf("%3d ", stat[i][j]);
			}
			cout << '\n';
		}*/

		int cnt = 11; //스텟 별 노드 번호
		for (int i = 1; i <= 11; ++i) {
			for (int j = 1; j <= 11; ++j) {
				++cnt;
				if (stat[j][i] == 0) continue;
				//포지션 -> 스텟
				node[i].push_back(cnt);
				node[cnt].push_back(i);
				cap[i][cnt] = 1;
				cost[i][cnt] = -stat[j][i];
				cost[cnt][i] = stat[j][i];

				//스텟 -> 사람
				node[cnt].push_back(P + j);
				node[P + j].push_back(cnt);
				cap[cnt][P + j] = 1;

				//사람 -> END
				node[P+j].push_back(END);
				node[END].push_back(P+j);
				cap[P+j][END] = 1;
			}
		}

		MCMF();
		cout << -ret << '\n';
	}

	return 0;
}
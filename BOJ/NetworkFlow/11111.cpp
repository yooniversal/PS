//11111
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

const int SIZE = 2505, START = 2500 + 1, END = 2500 + 2;
int n, m, dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int cap[SIZE][SIZE], flo[SIZE][SIZE], from[SIZE], cost[SIZE][SIZE], dist[SIZE];
int score[5][5] = {
		{10,8,7,5,1},
		{8,6,4,3,1},
		{7,4,3,2,1},
		{5,3,2,2,1},
		{1,1,1,1,0}
};
bool inQueue[SIZE];
char a[SIZE][SIZE];
vi adj[SIZE];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

//간선
void add(int u, int v, int capacity, int COST) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	cap[u][v] = capacity;
	cost[u][v] = COST;
	cost[v][u] = -COST;
}

int MCMF() {
	int ret = 0;
	while (1) {
		fill(from, from + SIZE, -1);
		fill(dist, dist + SIZE, -INF);
		fill(inQueue, inQueue + SIZE, 0);
		queue<int> q;
		dist[START] = 0;
		inQueue[START] = true;
		q.push(START);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			inQueue[cur] = false;
			for (auto& next : adj[cur]) {
				if (cap[cur][next] - flo[cur][next] > 0 && dist[next] < dist[cur] + cost[cur][next]) {
					dist[next] = dist[cur] + cost[cur][next];
					from[next] = cur;
					if (!inQueue[next]) {
						inQueue[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (dist[END] < 0) break;

		for (int i = END; i != START; i = from[i]) {
			ret += cost[from[i]][i];
			flo[from[i]][i] += 1;
			flo[i][from[i]] -= 1;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
		a[i][j] = a[i][j] == 'F' ? 'E' : a[i][j];
	}

	// 등급 -> (인접) 등급
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (i%2 != j%2) continue;
		for (int k = 0; k < 4; ++k) {
			int nx = i + dx[k], ny = j + dy[k];
			if (OOB(nx, ny)) continue;
			int cur = i * m + j, next = nx * m + ny;
			add(cur, next, 1, score[a[i][j] - 'A'][a[nx][ny] - 'A']);
		}
	}

	// START -> 등급, 등급 -> END
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		int next = i * m + j;
		if (i%2 == j%2) {
			add(START, next, 1, 0);
		}
		else {
			add(next, END, 1, 0);
		}
	}

	cout << MCMF() << '\n';

	return 0;
}
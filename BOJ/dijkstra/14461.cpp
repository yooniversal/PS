//14461
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 1234567;

struct P {
	int cur, distance, remain;
};

struct cmp {
	bool operator()(P& a, P& b) {
		return a.distance > b.distance;
	}
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int dist[MAX][3], MAP[101][101];
int n, t;
vii a[MAX];

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i) for (int j = 0; j < 3; ++j) dist[i][j] = INF;
	dist[start][0] = dist[start][1] = dist[start][2] = 0;
	priority_queue<P, vector<P>, cmp> pq;
	pq.push({ start, 0, 2 });
	while (!pq.empty()) {
		int cur = pq.top().cur, distance = pq.top().distance, remain = pq.top().remain; pq.pop();
		if (dist[cur][remain] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = remain == 0 ? distance + next.second + MAP[next.first / n][next.first % n] : distance + next.second;
			int nextRemain = remain == 0 ? 2 : remain - 1;
			if (nextDist < dist[next.first][nextRemain]) {
				//printf("cx:%d cy:%d nx:%d ny:%d remain:%d nextDist:%d\n", cur/n, cur%n, next.first/n, next.first%n, remain, nextDist);
				dist[next.first][nextRemain] = nextDist;
				pq.push({ next.first, nextDist, nextRemain });
			}
		}
	}
}

int f(int x, int y) { return x * n +y; }
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> t;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> MAP[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		for (int d = 0; d < 4; ++d) {
			int nx = i + dx[d], ny = j + dy[d];
			if (OOB(nx, ny)) continue;
			a[f(i, j)].push_back({ f(nx, ny), t });
		}
	}

	dijkstra(0);

	int ret = INF;
	for (int i = 0; i < 3; ++i)
		ret = min(ret, dist[f(n - 1, n - 1)][i]);
	cout << ret << '\n';

	return 0;
}
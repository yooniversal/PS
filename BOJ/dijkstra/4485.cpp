//4485
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 15626
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int dist[MAX];
int n;
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	fill(dist, dist + MAX, INF);
	memset(chk, 0, sizeof(chk));
	dist[start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vvi m(n, vi(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> m[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (OOB(nx, ny)) continue;
					a[i * n + j].push_back({ nx * n + ny, m[nx][ny] });
				}
			}
		}
		dijkstra(0);
		cout << "Problem " << ++cnt << ": " << dist[n * n - 1] + m[0][0] << '\n';

		for (int i = 0; i < MAX; ++i) a[i].clear();
	}

	return 0;
}
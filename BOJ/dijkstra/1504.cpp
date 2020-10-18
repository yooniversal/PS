//1504
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[801][801];
int n;
vii a[801];

void dijkstra(int start) {
	dist[start][start] = 0;
	priority_queue<ii> pq; //가까운 순서대로 처리하기 위함
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		//최단거리가 아님
		if (dist[start][cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (dist[start][next.first] > nextDist) {
				dist[start][next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 801; ++i)
		for (int j = 0; j < 801; ++j)
			dist[i][j] = INF;

	int n, e; cin >> n >> e;
	while (e--) {
		int st, ed, d; cin >> st >> ed >> d;
		a[st].push_back({ ed, d });
		a[ed].push_back({ st, d });
	}
	int ms, me; cin >> ms >> me;

	dijkstra(1);
	dijkstra(ms);
	dijkstra(me);

	int ret = INF, ret2 = INF;
	if (!(dist[1][ms] == INF || dist[ms][me] == INF || dist[me][n] == INF)) ret = min(ret, dist[1][ms] + dist[ms][me] + dist[me][n]);
	if (!(dist[1][me] == INF || dist[me][ms] == INF || dist[ms][n] == INF)) ret2 = min(ret2, dist[1][me] + dist[me][ms] + dist[ms][n]);
	if (ret == INF && ret2 == INF) cout << -1;
	else cout << min(ret, ret2);

	return 0;
}
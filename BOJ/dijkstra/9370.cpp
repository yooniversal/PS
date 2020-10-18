//9370
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[2001][2001];
vii a[2001];

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

	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 2001; ++i) {
			for (int j = 0; j < 2001; ++j)
				dist[i][j] = INF;
			a[i].clear();
		}

		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;
		while (m--) {
			int st, ed, d; cin >> st >> ed >> d;
			a[st].push_back({ ed, d });
			a[ed].push_back({ st, d });
		}
		vi arrive(t);
		for (int i = 0; i < t; ++i) cin >> arrive[i];

		dijkstra(s);
		dijkstra(g);
		dijkstra(h);

		vi ret;
		if (dist[s][g] != INF && dist[g][h] != INF) {
			int mid = dist[s][g] + dist[g][h];
			for (int& to : arrive) {
				if (dist[h][to] == INF) continue;
				if (mid + dist[h][to] == dist[s][to]) ret.push_back(to);
			}
		}
		if (dist[s][h] != INF && dist[h][g] != INF) {
			int mid2 = dist[s][h] + dist[h][g];
			for (int& to : arrive) {
				if (dist[g][to] == INF) continue;
				if (mid2 + dist[g][to] == dist[s][to]) ret.push_back(to);
			}
		}
		sort(ret.begin(), ret.end());
		bool chk[2001] = { 0, };
		for (auto& r : ret) {
			if (chk[r]) continue;
			chk[r] = true;
			cout << r << " ";
		}
		cout << '\n';
	}
	

	return 0;
}
//16167
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int prev, here, dist, cnt;
	P(int a, int b, int c, int d) : prev(a), here(b), dist(c), cnt(d) {}
};

int d[101][101];
int mid[101];
vi adj[101];
queue<P> q;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			if (i != j)
				d[i][j] = INF;

	int n, r; cin >> n >> r;
	while (r--) {
		int s, e, c, ac, t; cin >> s >> e >> c >> ac >> t;
		int dist = c;
		if (t > 10) dist += (t - 10) * ac;
		d[s][e] = min(d[s][e], dist);
		adj[s].push_back(e);
	}

	fill(mid, mid + 101, INF);
	//BFS·Î Å½»ö
	q.push(P(0, 1, 0, 1));
	while (!q.empty()) {
		P cur = q.front(); q.pop();
		if (cur.here == n) continue;
		for (auto& next : adj[cur.here]) {
			if (cur.prev == next) continue;
			if (cur.dist + d[cur.here][next] == d[1][next]) {
				if (mid[next] > cur.cnt + 1) {
					mid[next] = cur.cnt + 1;
					q.push(P(cur.here, next, cur.dist + d[cur.here][next], cur.cnt + 1));
				}
			}
			if (cur.dist + d[cur.here][next] < d[1][next]) {
				d[1][next] = cur.dist + d[cur.here][next];
				mid[next] = cur.cnt + 1;
				q.push(P(cur.here, next, cur.dist + d[cur.here][next], cur.cnt + 1));
			}
		}
	}

	if (d[1][n] == INF) cout << "It is not a great way.";
	else cout << d[1][n] << ' ' << mid[n];

	return 0;
}
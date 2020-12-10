//2398
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int dist[MAX][MAX], from[MAX][MAX];
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i) {
		dist[start][i] = INF;
		chk[i] = false;
	}

	dist[start][start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[start][cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (nextDist < dist[start][next.first]) {
				dist[start][next.first] = nextDist;
				from[start][next.first] = cur;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}
	int s1, s2, s3; cin >> s1 >> s2 >> s3;
	dijkstra(s1);
	dijkstra(s2);
	dijkstra(s3);
	int minDist = INF, arrival = 0;
	for(int i=1; i<=n; ++i)
		if (minDist > dist[s1][i] + dist[s2][i] + dist[s3][i]) {
			minDist = dist[s1][i] + dist[s2][i] + dist[s3][i];
			arrival = i;
		}
	
	vii ret;
	for (int i = arrival; i != s1; i = from[s1][i]) ret.push_back({ i, from[s1][i] });
	for (int i = arrival; i != s2; i = from[s2][i]) ret.push_back({ i, from[s2][i] });
	for (int i = arrival; i != s3; i = from[s3][i]) ret.push_back({ i, from[s3][i] });

	cout << minDist << ' ' << ret.size() << '\n';
	for (auto r : ret) cout << r.first << ' ' << r.second << '\n';

	return 0;
}
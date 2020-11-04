//1238
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX], returnDist[MAX];
bool chk[MAX];
vii adj[MAX];

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
		for (auto& next : adj[cur]) {
			int nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, x; cin >> n >> m >> x;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
    }

	dijkstra(x);
	for (int i = 1; i <= n; ++i)
		if (dist[i] != INF)
			returnDist[i] = dist[i];

	for (int i = 1; i <= n; ++i) {
		if (i == x) continue;
		dijkstra(i);
		if (dist[x] != INF)
			returnDist[i] += dist[x];
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret = max(ret, returnDist[i]);
			
	cout << ret;

    return 0;
}
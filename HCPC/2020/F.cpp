#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[1001], rev[1001], jieun[1001];
bool chk[1001];
int used[1001]; //얼마만에 왔는지
vii a[1001];

struct P {
	int u, v, w;
};

void dijkstra(int start) {
	fill(d, d + 1001, INF);
	memset(chk, 0, sizeof(chk));
	d[start] = 0;
	priority_queue<ii> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second, distance = -pq.top().first; pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (d[cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (used[cur] < nextDist) nextDist += next.second;
			if (nextDist < d[next.first]) {
				rev[next.first] = cur;
				d[next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, s, g; cin >> n >> m >> k >> s >> g;
	vector<P> path;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({ v, 2*w });
		a[v].push_back({ u, 2*w });
		path.push_back({ u, v, w });
	}

	for (int i = 0; i <= n; ++i) used[i] = INF;
	dijkstra(s);
	for (int i = g; i != 0; i = rev[i]) {
		//printf("%d ", i);
		used[i] = d[i];
	}
	int J = d[g];

	for (int i = 0; i <= n; ++i) a[i].clear();
	for (int i = 0; i < path.size(); ++i) {
		int u = path[i].u, v = path[i].v, w = path[i].w;
		a[u].push_back({ v, w });
		a[v].push_back({ u, w });
	}

	bool ret = true;
	while (k--) {
		int x; cin >> x;
		if (!ret) continue;
		dijkstra(x);
		if (J >= d[g]) ret = false;
	}
	
	if (ret) cout << "We don't abandon team members";
	else cout << "Gain Jui";

	return 0;
}
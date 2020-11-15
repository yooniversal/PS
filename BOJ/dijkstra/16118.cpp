//16118
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int cur, d, prev;
};

struct cmp {
	bool operator()(P& a, P& b) {
		return a.d > b.d;
	}
};

int n, m;
int dist[MAX][2], foxdist[MAX];
bool chk[MAX][2], foxchk[MAX];
vii fast[MAX], slow[MAX], foxroute[MAX];

void wolve(int start) {
	for (int i = 0; i < MAX; ++i)
		dist[i][0] = dist[i][1] = INF;
	priority_queue<P, vector<P>, cmp> pq;
	pq.push({ start, 0, 0 });
	while (!pq.empty()) {
		int cur = pq.top().cur, d = pq.top().d, prev = pq.top().prev; pq.pop();
		if (dist[cur][prev] < d) continue;
		//이전에 오솔길을 안갔다면
		if (prev == 0) {
			for (auto& next : fast[cur]) {
				int nextDist = d + next.second;
				if (nextDist < dist[next.first][1] || !chk[next.first][1]) {
					chk[next.first][1] = true;
					dist[next.first][1] = nextDist;
					pq.push({ next.first, nextDist, 1 });
				}
			}
		}
		//이전에 오솔길을 갔다면
		else {
			for (auto& next : slow[cur]) {
				int nextDist = d + next.second;
				if (nextDist < dist[next.first][!prev] || !chk[next.first][0]) {
					chk[next.first][0] = true;
					dist[next.first][0] = nextDist;
					pq.push({ next.first, nextDist, 0 });
				}
			}
		}
	}
}

void fox(int start) {
	for (int i = 0; i < MAX; ++i) foxdist[i] = INF;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second, d = pq.top().first; pq.pop();
		if (foxchk[cur]) continue;
		foxchk[cur] = true;
		if (foxdist[cur] < d) continue;
		for (auto& next : foxroute[cur]) {
			int nextDist = d + next.second;
			if (nextDist < foxdist[next.first]) {
				foxdist[next.first] = nextDist;
				pq.push({ nextDist, next.first });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		foxroute[u].push_back({ v, w * 2 });
		fast[u].push_back({ v, w });
		slow[u].push_back({ v, w * 4 });

		foxroute[v].push_back({ u, w * 2 });
		fast[v].push_back({ u, w });
		slow[v].push_back({ u, w * 4 });
	}
	wolve(1);
	fox(1);

	int ret = 0;
	for (int i = 2; i <= n; ++i) {
		if (foxdist[i] < min(dist[i][0], dist[i][1])) ++ret;
	}
	cout << ret;

	return 0;
}
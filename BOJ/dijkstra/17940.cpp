//17940
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct T {
	int d, t; //°Å¸®, ¿ª
};

T dist[MAX];
int n;
int train[MAX];
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
	dist[start].d = dist[start].t = 0;
	priority_queue<pair<ii, int>, vector<pair<ii, int>>, greater<pair<ii, int>>> pq;
	pq.push({ {0, 0}, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int trains = pq.top().first.first, distance = pq.top().first.second;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur].d < distance || dist[cur].t < trains) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			int add = train[cur] == train[next.first] ? 0 : 1;
			if (dist[next.first].d > nextDist && dist[next.first].t >= trains+add ) {
				dist[next.first].d = nextDist;
				dist[next.first].t = trains + add;
				pq.push({ {trains + add, nextDist}, next.first });
			}
		}
	}
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX; ++i) {
		dist[i].d = dist[i].t = INF;
	}

	int n, e; cin >> n >> e;
	for (int i = 0; i < n; ++i) cin >> train[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int dist; cin >> dist;
			if (dist == 0) continue;
			a[i].push_back({ j, dist });
		}
	}

	dijkstra(0);

	cout << dist[e].t << ' ' << dist[e].d;

    return 0;
}
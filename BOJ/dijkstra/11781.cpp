//11781
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

struct P {
	ll v, w, r;
};

struct node{
	ll v, now;
};

struct cmp {
	bool operator()(node& A, node& B) {
		return A.now > B.now;
	}
};

ll dist[MAX];
bool chk[MAX];
ll n, m, s, e;
vector<P> a[MAX];

void dijkstra(int start) {
	for (int i = 0; i < MAX; ++i) dist[i] = LLONG_MAX;
	dist[start] = 0;
	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		ll cur = pq.top().v, now = pq.top().now; pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		if (dist[cur] < now) continue;
		for (auto& next : a[cur]) {
			ll nextDist = now;
			if (next.r == 1) {
				if (now < s) {
					if (now + next.w <= s) nextDist += next.w;
					else if (next.w <= (s+e)/2-now) nextDist += next.w * 2 - s + now;
					else nextDist += next.w + (e - s)/2;
				}
				else if (s <= now && now < e) {
					if (e - now >= next.w * 2) nextDist += next.w * 2;
					else nextDist += next.w + (e - now) / 2;
				}
				else nextDist += next.w;
			}
			else nextDist += next.w;
			if (dist[next.v] > nextDist) {
				dist[next.v] = nextDist;
				pq.push({ next.v, nextDist });
			}
		}
	}
}

int main() {	

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> s >> e;
	s *= 2, e *= 2;
	while (m--) {
		ll u, v, w, t1, t2;
		cin >> u >> v >> w >> t1 >> t2;
		a[u].push_back({ v,w*2,t1 });
		a[v].push_back({ u,w*2,t2 });
	}
	dijkstra(1);
	ll ret = 0;
	for (int i = 1; i <= n; ++i) ret = max(ret, dist[i]);
	if (ret % 2 == 0) cout << ret / 2 << '\n';
	else cout << ret / 2 << ".5\n";

	return 0;
}
//2644
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

struct P {
	int cur, cnt;
};

vi adj[101];
bool chk[101];

int BFS(int x, int y) {
	int ret = 0;
	queue<P> q;
	q.push({ x, 0 });
	chk[x] = true;
	while (!q.empty()) {
		int cur = q.front().cur, cnt = q.front().cnt; q.pop();
		if (cur == y) return cnt;
		for (auto& next : adj[cur]) {
			if (chk[next]) continue;
			chk[next] = true;
			q.push({ next, cnt + 1 });
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, m; cin >> n >> a >> b >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	cout << BFS(a, b) << '\n';

	return 0;
}
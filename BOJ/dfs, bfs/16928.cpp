//16928
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int n, m;
int MOVE[101], d[101];

int BFS() {
	queue<ii> q;
	d[1] = 0;
	q.push({ 1, 0 });
	while (!q.empty()) {
		int cur = q.front().first, cnt = q.front().second; q.pop();
		if (cur == 100) return cnt;
		for (int i = 1; i <= 6; ++i) {
			if (cur + i > 100) continue;
			int next = MOVE[cur + i] == 0 ? cur + i : MOVE[cur + i];
			if (d[next] != -1) continue;
			d[next] = d[cur] + 1;
			q.push({ next, cnt + 1 });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(d, -1, sizeof(d));
	cin >> n >> m;
	n += m;
	while(n--) {
		int u, v; cin >> u >> v;
		MOVE[u] = v;
	}

	cout << BFS();

	return 0;
}
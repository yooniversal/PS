//11657
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll d[501];
vii a[501];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	fill(d, d + 501, INF);
	int n, m; cin >> n >> m;
	while (m--) {
		int s, e, dist; cin >> s >> e >> dist;
		a[s].push_back({ e, dist });
	}

	bool minus = false;
	d[1] = 0; //start
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (auto& adj : a[j]) {
				int next = adj.first, dist = adj.second;
				if (d[j] != INF && d[next] > d[j] + dist) {
					d[next] = d[j] + dist;
					if (i == n) minus = true;
				}
			}
		}
	}
	if (minus) cout << -1;
	else {
		for (int i = 2; i <= n; ++i) {
			if (d[i] == INF) cout << -1 << '\n';
			else cout << d[i] << '\n';
		}
	}

	return 0;
}
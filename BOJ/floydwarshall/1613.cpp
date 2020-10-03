//1613
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[405][405];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 405; ++i)
		for (int j = 0; j < 405; ++j)
			if (i != j)
				d[i][j] = INF;

	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		d[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		if (d[a][b] == INF && d[b][a] == INF) cout << 0 << '\n';
		if (d[a][b] == INF && d[b][a] != INF) cout << 1 << '\n';
		if (d[a][b] != INF && d[b][a] == INF) cout << -1 << '\n';
	}

	return 0;
}
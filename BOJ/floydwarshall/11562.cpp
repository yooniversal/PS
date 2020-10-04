//11562
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[255][255];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 255; ++i)
		for (int j = 0; j < 255; ++j)
			if (i != j)
				d[i][j] = INF;

	int n, m; cin >> n >> m;
	while (m--) {
		int u, v, b; cin >> u >> v >> b;
		if (b == 0) {
			d[u][v] = 0;
			d[v][u] = 1;
		}
		else {
			d[u][v] = 0;
			d[v][u] = 0;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	int k; cin >> k;
	while (k--) {
		int s, e; cin >> s >> e;
		cout << d[s][e] << '\n';
	}

	return 0;
}
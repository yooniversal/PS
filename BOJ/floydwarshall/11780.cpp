//11780
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[105][105];
vi r[105][105];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			if (i != j)
				d[i][j] = INF;

	int n, m; cin >> n >> m;
	while (m--) {
		int u, v, b; cin >> u >> v >> b;
		d[u][v] = min(d[u][v], b);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					r[i][j].clear();
					for (int R : r[i][k]) r[i][j].push_back(R);
					r[i][j].push_back(k);
					for (int R : r[k][j]) r[i][j].push_back(R);
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == INF) cout << 0 << " ";
			else cout << d[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) cout << 0;
			else {
				cout << 2+r[i][j].size() << " " << i << " ";
				for (int& route : r[i][j])
					cout << route << " ";
				cout << j << " ";
			}
			cout << '\n';
		}
	}


	return 0;
}
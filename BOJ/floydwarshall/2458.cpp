//2458
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[501][501];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 501; ++i)
		for (int j = 0; j < 501; ++j)
			if (i != j)
				d[i][j] = INF;

	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		d[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j)
			if (d[i][j] == INF && d[j][i] == INF) {
				flag = false;
				break;
			}
		if (flag) ++ret;
	}
	cout << ret;

	return 0;
}
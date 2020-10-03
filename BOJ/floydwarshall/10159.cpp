//10159
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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 105; ++j)
			if(i != j)
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

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j)
			if (d[i][j] == INF && d[j][i] == INF) ++cnt;
		cout << cnt << '\n';
	}

	return 0;
}
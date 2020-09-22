//18111
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX][MAX];
int all[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				dist[i][j] = INF;

	while (m--) {
		int a, b; cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int minn = INF;
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 1; j <= n; ++j)
			tmp += dist[i][j];
		all[i] = tmp;
		minn = min(minn, all[i]);
	}

	int ret = INF;
	for (int i = 1; i <= n; ++i) {
		if (minn == all[i]) {
			ret = min(ret, i);
		}
	}

	cout << ret;

	return 0;
}
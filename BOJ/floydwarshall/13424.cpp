//13424
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
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

	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 105; ++i)
			for (int j = 0; j < 105; ++j)
				if (i != j)
					d[i][j] = INF;

		int n, m; cin >> n >> m;
		while (m--) {
			int a, b, c; cin >> a >> b >> c;
			d[a][b] = c;
			d[b][a] = c;
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];

		int k; cin >> k;
		vi fr(k);
		for (int i = 0; i < k; ++i) cin >> fr[i];

		vii dist;
		int minn = INF;
		for (int i = 1; i <= n; ++i) {
			int dsum = 0;
			for (int f = 0; f < k; ++f)
				dsum += d[fr[f]][i];
			minn = min(minn, dsum);
			dist.push_back({ minn, i });
		}
		int ret = INF;
		for (int i = 0; i < n; ++i)
			if (dist[i].first == minn)
				ret = min(ret, dist[i].second);
		cout << ret << '\n';
	}

	return 0;
}
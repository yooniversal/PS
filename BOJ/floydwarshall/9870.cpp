//9870
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll d[201][201];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < 201; ++j)
			if (i != j)
				d[i][j] = INF;
	int n, m, k, q; cin >> n >> m >> k >> q;
	while (m--) {
		int a, b; ll dist; cin >> a >> b >> dist;
		d[a][b] = min(d[a][b], dist);
	}

	for (int x = 1; x <= n; ++x)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][x] + d[x][j]);

	int cnt = 0; ll sum = 0;
	while (q--) {
		int a, b; cin >> a >> b;
		ll tmp = INF;
		for (int i = 1; i <= k; ++i)
			tmp = min(tmp, d[a][i] + d[i][b]);
		if (tmp != INF) {
			++cnt;
			sum += tmp;
		}
	}
	cout << cnt << '\n' << sum;

	return 0;
}
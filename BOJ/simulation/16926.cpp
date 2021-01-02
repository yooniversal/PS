//16926
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int n, m, r, maxSqu;
int a[301][301], ret[301][301];
vi Squ[151];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> r;
	maxSqu = min(n, m) / 2;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int t = 1; t <= maxSqu; ++t) {
		for (int y = t - 1; y <= m - t; ++y) Squ[t].push_back(a[t - 1][y]);
		for (int x = t; x <= n - t; ++x) Squ[t].push_back(a[x][m - t]);
		for (int y = m - t - 1; y >= t - 1; --y) Squ[t].push_back(a[n - t][y]);
		for (int x = n - t - 1; x >= t; --x) Squ[t].push_back(a[x][t - 1]);
	}

	for (int t = 1; t <= maxSqu; ++t) {
		int len = 2 * n + 2 * m - 4 - 8 * (t - 1);
		int cur = r % len;
		for (int y = t - 1; y <= m - t; ++y) {
			if (cur >= Squ[t].size()) cur = 0;
			ret[t - 1][y] = Squ[t][cur++];
		}
		for (int x = t; x <= n - t; ++x) {
			if (cur >= Squ[t].size()) cur = 0;
			ret[x][m - t] = Squ[t][cur++];
		}
		for (int y = m - t - 1; y >= t - 1; --y) {
			if (cur >= Squ[t].size()) cur = 0;
			ret[n - t][y] = Squ[t][cur++];
		}
		for (int x = n - t - 1; x >= t; --x) {
			if (cur >= Squ[t].size()) cur = 0;
			ret[x][t - 1] = Squ[t][cur++];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';

	return 0;
}
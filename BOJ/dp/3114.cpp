//3114
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1501, INF = 1000000001, MOD = 1234567;

int dx[] = { 0,1,1 }, dy[] = { 1,1,0 };
int n, m, a[MAX][MAX][2], pSum[MAX][MAX][2];
int cache[MAX][MAX][2];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int f(int x, int y, int prev) {
	if (x == n - 1 && y == m - 1) return prev ? 0 : pSum[x - 1][y][1];
	int& ret = cache[x][y][prev];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 3; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (i <= 1) {
			int add = 0;
			if (prev) {
				if (x != n - 1) add += pSum[x + 1][y][0];
			}
			else {
				if (x != 0) add += pSum[x - 1][y][1];
				if (x != n - 1) add += pSum[x + 1][y][0];
			}
			ret = max(ret, f(nx, ny, 0) + add);
		}
		else {
			int add = 0;
			if (x != 0 && !prev) add += pSum[x - 1][y][1];
			ret = max(ret, f(nx, ny, 1) + add);
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			string s; cin >> s;
			int N = 0;
			for (int id = 1; id < s.size(); ++id)
				N = N * 10 + s[id] - '0';
			if (s[0] == 'A') a[i][j][0] = N;
			else a[i][j][1] = N;
		}
	}

	for (int c = 0; c < m; ++c) {
		for (int r = n - 1; r >= 0; --r)
			if (r != n - 1) pSum[r][c][0] = pSum[r + 1][c][0] + a[r][c][0];
			else pSum[r][c][0] = a[r][c][0];
		for (int r = 0; r < n; ++r)
			if (r != 0) pSum[r][c][1] = pSum[r - 1][c][1] + a[r][c][1];
			else pSum[r][c][1] = a[r][c][1];
	}

	cout << f(0,0,0) << '\n';

	return 0;
}
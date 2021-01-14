//16957
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,-1,-1,0,0,1,1,1 }, dy[] = { 1,0,-1,1,-1,1,0,-1 };
int r, c, a[501][501], cache[501][501], ret[501][501];

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

int f(int x, int y) {
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = x * c + y;
	int tmp = a[x][y];
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (tmp > a[nx][ny]) {
			tmp = a[nx][ny];
			ret = f(nx, ny);
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> r >> c;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) cin >> a[i][j];
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		++ret[f(i, j) / c][f(i, j) % c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
//2169
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1005][1005][3];
int a[1005][1005];
int dx[] = { 0, 0, 1 }, dy[] = { -1, 1, 0 };
int n, m;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int f(int x, int y, int dir) {
	if (OOB(x, y)) return -INF;
	if (x==n-1 && y==m-1) return a[x][y];
	int& ret = cache[x][y][dir];
	if (ret != -1e6) return ret;
	ret = -INF;
	for (int i = 0; i < 3; ++i) {
		if (dir == 0 && i == 1) continue;
		if (dir == 1 && i == 0) continue;
		int nx = x + dx[i], ny = y + dy[i];
		ret = max(ret, f(nx, ny, i) + a[x][y]);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 1005; ++i)
		for (int j = 0; j < 1005; ++j)
			for(int k=0; k<3; ++k)
				cache[i][j][k] = -1e6;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	cout << f(0, 0, 2);

	return 0;
}
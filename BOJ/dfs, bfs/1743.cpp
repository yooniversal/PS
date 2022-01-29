//1743
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, m, k;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[101][101], a[101][101];

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

int BFS(int x, int y) {
	int ret = 0;
	queue<ii> q;

	chk[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		ii xy = q.front(); q.pop();
		int x = xy.first, y = xy.second;
		++ret;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny) || chk[nx][ny] || !a[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		a[--x][--y] = true;
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (chk[i][j] || !a[i][j]) continue;
		ret = max(ret, BFS(i, j));
	}

	cout << ret << '\n';

	return 0;
}
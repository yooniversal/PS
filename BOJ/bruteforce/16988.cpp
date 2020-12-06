//16988
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int n, m, cnt, S;
int area[21][21], a[21][21];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[21][21];
vii blank;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void makeArea(int x, int y, int cnt) {
	area[x][y] = cnt;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (chk[nx][ny] || area[nx][ny] || a[nx][ny] != 2) continue;
		chk[nx][ny] = true;
		makeArea(nx, ny, cnt);
	}
}

void count(int x, int y) {
	++S;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (chk[nx][ny]) continue;
		chk[nx][ny] = true;
		if (a[nx][ny] == 0) blank.push_back({ nx, ny });
		else if (a[nx][ny] == 2) count(nx, ny);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (chk[i][j] || a[i][j] != 2) continue;
		chk[i][j] = true;
		makeArea(i, j, ++cnt);
	}

	int ret = 0;
	for (int i = 0; i < n * m - 1; ++i) {
		if (a[i / m][i % m] != 0) continue;
		for (int j = i + 1; j < n * m; ++j) {
			int sx = i / m, sy = i % m, ex = j / m, ey = j % m;
			if (a[ex][ey] != 0) continue;
			memset(chk, 0, sizeof(chk));
			a[sx][sy] = a[ex][ey] = 1;
			int sum = 0;
			for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) {
				if (a[x][y] != 2 || chk[x][y]) continue;
				chk[x][y] = true;
				count(x, y);
				if (blank.size() == 0) sum += S;
				else
					for (auto b : blank) chk[b.first][b.second] = false;
				blank.clear(); S = 0;
			}
			a[sx][sy] = a[ex][ey] = 0;
			ret = max(ret, sum);
		}
	}

	cout << ret << '\n';

	return 0;
}
//16929
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

char a[51][51];
int n, m, dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[51][51];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void DFS(int sx, int sy, int x, int y, int cnt, char cur) {
	if (sx == x && sy == y) {
		if (cnt >= 4) {
			cout << "Yes\n";
			exit(0);
		}
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (a[nx][ny] != cur) continue;
		if (chk[nx][ny]) continue;
		chk[nx][ny] = true;
		DFS(sx, sy, nx, ny, cnt + 1, cur);
		chk[nx][ny] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		DFS(i, j, i, j, 1, a[i][j]);
	}

	cout << "No\n";

	return 0;
}
//16234
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int a[51][51];
int n, l, r, sum;
bool chk[51][51];
vii area;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void DFS(int x, int y) {
	area.push_back({ x, y });
	sum += a[x][y];
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (chk[nx][ny]) continue;
		if (l <= abs(a[x][y] - a[nx][ny]) && abs(a[x][y] - a[nx][ny]) <= r) {
			chk[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	
	int ret = 0;
	while (1) {
		memset(chk, 0, sizeof(chk));
		bool flag = false;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (chk[i][j]) continue;
			chk[i][j] = true;
			DFS(i, j);

			int to = sum / area.size();
			for (auto p : area) {
				a[p.first][p.second] = to;
			}
			if (area.size() > 1) flag = true;
			sum = 0;
			area.clear();
		}
		if (flag) ++ret;
		else break;
	}
	cout << ret << '\n';

	return 0;
}
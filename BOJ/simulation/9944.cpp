//9944
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;
bool a[31][31];

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int Search(int x, int y, int cnt, int remain) {
	bool stop = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny) || a[nx][ny]) continue;
		stop = false;
		break;
	}
	if (stop) {
		return (remain == 0) ? cnt : -1;
	}

	int ret = -1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		int pass = 1;
		if (OOB(nx, ny) || a[nx][ny]) continue;
		while (!OOB(nx, ny) && !a[nx][ny]) {
			a[nx][ny] = true;
			nx += dx[i], ny += dy[i];
			--remain;
		}
		nx -= dx[i], ny -= dy[i];

		int tmp = Search(nx, ny, cnt + 1, remain);
		if (tmp != -1) {
			if (ret == -1 || ret > tmp) {
				ret = tmp;
			}
		}

		while (nx != x || ny != y) {
			a[nx][ny] = false;
			nx -= dx[i], ny -= dy[i];
			++remain;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testcase = 1;
	while (cin >> n >> m) {
		memset(a, 0, sizeof(a));

		int roads = 0;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			for (int j = 0; j < m; ++j) {
				if (s[j] == '*') a[i][j] = true;
				else {
					a[i][j] = false;
					++roads;
				}
			}
		}

		int ret = -1;
		for(int x = 0; x<n; ++x){
			for (int y = 0; y < m; ++y) {
				if (a[x][y]) continue;
				a[x][y] = true;
				int tmp = Search(x, y, 0, roads-1);
				if (tmp != -1) {
					if (ret == -1 || ret > tmp) {
						ret = tmp;
					}
				}
				a[x][y] = false;
			}
		}

		printf("Case %d: %d\n", testcase++, ret);
	}

	return 0;
}
//14503
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int a[51][51];

int solve(int sx, int sy, int dir) {
	int ret = 0;
	int x = sx, y = sy;
	while (1) {
		if (a[x][y] == 0) {
			a[x][y] = 2;
			++ret;
		}
		//사방 탐색
		bool flag = false;
		for (int i = 1; i < 5; ++i) {
			int d = (dir + i) % 4;
			int nx = x + dx[d], ny = y + dy[d];
			if (a[nx][ny]) continue;
			x = nx; y = ny; dir = d;
			flag = true;
			break;
		}
		//사방이 벽이거나 다 닦여있음
		if (!flag) {
			int nx = x + dx[(dir + 2) % 4], ny = y + dy[(dir + 2) % 4];
			//후진 가능
			if (a[nx][ny] != 1) {
				x = nx; y = ny;
			}
			//후진 불가능
			else {
				break;
			}
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int sx, sy, dir; cin >> sx >> sy >> dir;
	if (dir == 1) dir = 3;
	else if (dir == 3) dir = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	cout << solve(sx, sy, dir);

	return 0;
}
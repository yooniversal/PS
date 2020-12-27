//16959
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, m, cur, cnt;
};

int dx[3][8] = {
	{ -2,-2,-1,-1,1,1,2,2 },
	{ -1,-1,1,1,0,0,0,0 },
	{ -1,0,0,1,0,0,0,0 }
};
int dy[3][8] = {
	{ -1,1,-2,2,-2,2,-1,1 },
	{ -1,1,-1,1,0,0,0,0 },
	{ 0,-1,1,0,0,0,0,0 }
};
int n, a[11][11];
bool chk[11][11][101][3];
queue<P> q;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int BFS() {
	int ret = INF;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, m = q.front().m;
		int cur = q.front().cur, cnt = q.front().cnt; q.pop();
		if (cur == n*n) {
			ret = min(ret, cnt);
			continue;
		}
		
		if (m == 0) {
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[m][i], ny = y + dy[m][i];
				if (OOB(nx, ny)) continue;
				int next = a[nx][ny] == cur + 1 ? cur + 1 : cur;
				if (chk[nx][ny][next][m]) continue;
				chk[nx][ny][next][m] = true;
				q.push({ nx,ny,m,next,cnt + 1 });
			}
		}
		else {
			for (int i = 0; i < 4; ++i) {
				for (int nx = x + dx[m][i], ny = y + dy[m][i]; ; nx += dx[m][i], ny += dy[m][i]) {
					bool flag = false;
					if (OOB(nx, ny)) break;
					int next = a[nx][ny] == cur + 1 ? cur + 1 : cur;
					if (chk[nx][ny][next][m]) continue;
					chk[nx][ny][next][m] = true;
					q.push({ nx,ny,m,next,cnt + 1 });
				}
			}
		}
		

		for (int i = 0; i < 3; ++i) {
			if (i == m) continue;
			if (chk[x][y][cur][i]) continue;
			chk[x][y][cur][i] = true;
			q.push({ x,y,i,cur,cnt + 1 });
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> a[i][j];
		if (a[i][j] == 1)
			for (int m = 0; m < 3; ++m) {
				q.push({ i,j,m,1,0 });
				chk[i][j][1][m] = true;
			}
	}

	cout << BFS() << '\n';

	return 0;
}
//14499
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[21][21];
int dice[7];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
int n, m, x, y, q;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

void convert(int dir) {
	int vd[7];
	for (int i = 1; i <= 6; ++i) vd[i] = dice[i];
	if (dir == 1) {
		dice[4] = vd[6];
		dice[1] = vd[4];
		dice[3] = vd[1];
		dice[6] = vd[3];
	}
	else if (dir == 2) {
		dice[6] = vd[4];
		dice[4] = vd[1];
		dice[1] = vd[3];
		dice[3] = vd[6];
	}
	else if (dir == 3) {
		dice[2] = vd[1];
		dice[1] = vd[5];
		dice[5] = vd[6];
		dice[6] = vd[2];
	}
	else {
		dice[2] = vd[6];
		dice[6] = vd[5];
		dice[5] = vd[1];
		dice[1] = vd[2];
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> x >> y >> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	while (q--) {
		int dir; cin >> dir;
		int nx = x + dx[dir - 1], ny = y + dy[dir - 1];
		if (OOB(nx, ny)) continue;
		convert(dir);
		if (a[nx][ny] == 0) a[nx][ny] = dice[6];
		else {
			dice[6] = a[nx][ny];
			a[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
		x = nx; y = ny;
	}

	return 0;
}
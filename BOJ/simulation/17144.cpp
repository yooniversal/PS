//17144
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c, t, cx=-1, cy=-1;
int a[51][51];

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

void spread() {
	vvi dust(r, vi(c, 0));
	for (int i = 0; i < r; ++i) 
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == 0 || a[i][j] == -1) continue;
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				if (OOB(nx, ny)) continue;
				if (a[nx][ny] == -1) continue;
				dust[nx][ny] += a[i][j] / 5;
				dust[i][j] -= a[i][j] / 5;
			}
		}
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			a[i][j] += dust[i][j];
}

void airCleaner() {
	int ux = cx - 1, uy = cy; //공기청정기 윗 부분
	--ux;
	if (!OOB(ux, uy)) {
		a[ux][uy] = 0;
		while (!OOB(ux - 1, uy)) {
			swap(a[ux][uy], a[ux - 1][uy]);
			--ux;
		}
		while (!OOB(ux, uy + 1)) {
			swap(a[ux][uy], a[ux][uy + 1]);
			++uy;
		}
		while (ux != cx - 1) {
			swap(a[ux][uy], a[ux + 1][uy]);
			++ux;
		}
		while (uy != cy + 1) {
			swap(a[ux][uy], a[ux][uy - 1]);
			--uy;
		}
	}

	int dx = cx, dy = cy; //공기청정기 아래 부분
	++dx;
	if (!OOB(dx, dy)) {
		a[dx][dy] = 0;
		while (!OOB(dx + 1, dy)) {
			swap(a[dx][dy], a[dx + 1][dy]);
			++dx;
		}
		while (!OOB(dx, dy + 1)) {
			swap(a[dx][dy], a[dx][dy + 1]);
			++dy;
		}
		while (dx != cx) {
			swap(a[dx][dy], a[dx - 1][dy]);
			--dx;
		}
		while (dy != cy + 1) {
			swap(a[dx][dy], a[dx][dy - 1]);
			--dy;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		cin >> a[i][j];
		if (a[i][j] == -1) cx = i, cy = j;
	}

	while (t--) {
		spread();
		airCleaner();
	}

	int ret = 0;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (a[i][j] == -1) continue;
		ret += a[i][j];
	}
	cout << ret << '\n';

	return 0;
}
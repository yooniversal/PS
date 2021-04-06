//20058
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int x, y, v;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, q, a[65][65];
int ret1, ret2, cnt;
bool chk[65][65];

bool OOB(int x, int y) { return x < 0 || x >= (1<<n) || y < 0 || y >= (1<<n); }

void turn(int sx, int sy, int ex, int ey) {
	// 테두리 돌리기
	vector<P> v;
	for (int y = sy; y <= ey; ++y) v.push_back({ sx + y - sy, ey, a[sx][y] });
	for (int x = sx; x <= ex; ++x) v.push_back({ ex, ey + sx - x, a[x][ey] });
	for (int y = sy; y <= ey; ++y) v.push_back({ sx + y - sy, sy, a[ex][y] });
	for (int x = sx; x <= ex; ++x) v.push_back({ sx, ey + sx - x, a[x][sy] });

	for (auto& cur : v) {
		a[cur.x][cur.y] = cur.v;
	}

	if (ex - sx == 1 && ey - sy == 1) return;
	turn(sx + 1, sy + 1, ex - 1, ey - 1);
}

void melt() {
	vii tmp;
	for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) {
		if (a[i][j] == 0) continue;
		int cnt = 0;
		for (int d = 0; d < 4; ++d) {
			int nx = i + dx[d], ny = j + dy[d];
			if (OOB(nx, ny) || a[nx][ny] == 0) continue;
			++cnt;
		}
		if (cnt < 3) tmp.emplace_back(make_pair(i, j));
	}

	for (auto& cur : tmp) {
		--a[cur.first][cur.second];
	}
}

void DFS(int x, int y) {
	ret2 = max(ret2, ++cnt);
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == 0) continue;
		chk[nx][ny] = true;
		DFS(nx, ny);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) {
		cin >> a[i][j];
	}
	for (int i = 0; i < q; ++i) {
		int L; cin >> L;
		if (L) {
			for (int x = 0; x < (1 << n); x += (1 << L)) {
				for (int y = 0; y < (1 << n); y += (1 << L)) {
					turn(x, y, x + (1 << L) - 1, y + (1 << L) - 1);
				}
			}
		}
		melt();
	}

	for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) {
		ret1 += a[i][j];
	}
	cout << ret1 << '\n';

	for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) {
		if (chk[i][j] || a[i][j] == 0) continue;
		chk[i][j] = true;
		cnt = 0;
		DFS(i, j);
	}
	cout << ret2 << '\n';

	return 0;
}
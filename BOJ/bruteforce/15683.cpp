//15683
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct info {
	int x, y, kind;
	info(int a, int b, int c) : x(a), y(b), kind(c) {}
};

int n, m;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0,-1,0,1 };
int ret = INF;
vector<info> cctv;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

void solve(int cur, int level, vvi a) {
	int nx = cctv[cur].x + dx[level];
	int ny = cctv[cur].y + dy[level];
	while (1) {
		if (OOB(nx, ny)) break;
		if (a[nx][ny] == 6) break;
		a[nx][ny] = cctv[cur].kind;
		nx += dx[level]; ny += dy[level];
	}
	if (cctv[cur].kind == 4 || cctv[cur].kind == 5) {
		nx = cctv[cur].x + dx[(level + 1) % 4];
		ny = cctv[cur].y + dy[(level + 1) % 4];
		while (1) {
			if (OOB(nx, ny)) break;
			if (a[nx][ny] == 6) break;
			a[nx][ny] = cctv[cur].kind;
			nx += dx[(level + 1) % 4]; ny += dy[(level + 1) % 4];
		}
	}
	if (cctv[cur].kind == 3 || cctv[cur].kind == 4 || cctv[cur].kind == 5) {
		nx = cctv[cur].x + dx[(level + 3) % 4];
		ny = cctv[cur].y + dy[(level + 3) % 4];
		while (1) {
			if (OOB(nx, ny)) break;
			if (a[nx][ny] == 6) break;
			a[nx][ny] = cctv[cur].kind;
			nx += dx[(level + 3) % 4]; ny += dy[(level + 3) % 4];
		}
	}
	if (cctv[cur].kind == 2 || cctv[cur].kind == 5) {
		nx = cctv[cur].x + dx[(level + 2) % 4];
		ny = cctv[cur].y + dy[(level + 2) % 4];
		while (1) {
			if (OOB(nx, ny)) break;
			if (a[nx][ny] == 6) break;
			a[nx][ny] = cctv[cur].kind;
			nx += dx[(level + 2) % 4]; ny += dy[(level + 2) % 4];
		}
	}

	if (cur < cctv.size() - 1) {
		if (cctv[cur + 1].kind == 1 || cctv[cur + 1].kind == 3 || cctv[cur + 1].kind == 4)
			for (int i = 0; i < 4; ++i) {
				solve(cur + 1, i, a);
			}
		else if (cctv[cur + 1].kind == 2)
			for (int i = 0; i < 2; ++i) {
				solve(cur + 1, i, a);
			}
		else
			solve(cur + 1, 0, a);
	}
	else {
		int tmp = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 0)
					++tmp;
		ret = min(ret, tmp);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	vvi a(n, vi(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0 || a[i][j] == 6) continue;
			cctv.push_back(info(i, j, a[i][j]));
		}

	if (cctv.size()) {
		for (int i = 0; i < 4; ++i)
			solve(0, i, a);
	}
	else {
		ret = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 0)
					++ret;
	}

	cout << ret;

	return 0;
}
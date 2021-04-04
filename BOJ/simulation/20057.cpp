//20057
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	int x, y, d;
};

int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };
int n, a[501][501];
double score[] = { 0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05 };
int NEXT[4][10][2] = {
	{{-1,0},{1,0},{-1,-1},{1,-1},{-2,-1},{2,-1},{-1,-2},{1,-2},{0,-3},{0,-2}},
	{{0,-1},{0,1},{1,-1},{1,1},{1,-2},{1,2},{2,-1},{2,1},{3,0},{2,0}},
	{{-1,0},{1,0},{-1,1},{1,1},{-2,1},{2,1},{-1,2},{1,2},{0,3},{0,2}},
	{{0,-1},{0,1},{-1,-1},{-1,1},{-1,-2},{-1,2},{-2,-1},{-2,1},{-3,0},{-2,0}}
};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int solve() {
	int ret = 0;
	queue<P> q;
	bool flag = false; // x==0, y==0
	for (int x = n / 2, y = n / 2, d = 0, t = 1;; d = (d+1)%4) {
		for (int j = 0; j < t; ++j) {
			q.push({ x, y, d });
			x += dx[d], y += dy[d];
			if (x == 0 && y == 0) flag = true;
		}
		if (flag) break;
		if (d == 1 || d == 3) ++t;
	}
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, d = q.front().d; q.pop();
		if (x == 0 && y == 0) break;
		int nx = x + dx[d], ny = y + dy[d];
		if (a[nx][ny] == 0) continue;
		int sum = 0;
		for (int i = 0; i < 10; ++i) {
			int nnx = x + NEXT[d][i][0], nny = y + NEXT[d][i][1];
			if (i != 9) {
				double v = a[nx][ny] * score[i];
				if (v == 0.0) continue;
				if (OOB(nnx, nny)) ret += floor(v);
				else a[nnx][nny] += floor(v);
				sum += floor(v);
			}
			else {
				if (OOB(nnx, nny)) ret += a[nx][ny] - sum;
				else a[nnx][nny] += a[nx][ny] - sum;
			}
		}
		a[nx][ny] = 0;
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
	}

	cout << solve() << '\n';

	return 0;
}
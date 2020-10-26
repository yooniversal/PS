//15684
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m, h;
int a[31][31];

//line번에 들어온게 line번으로 빠지면 true
bool pass(int line) {
	queue<ii> q;
	q.push({ 1, line });
	while (1) {
		int r = q.front().first, c = q.front().second; q.pop();
		if (r == h+1) {
			if (c == line) return true;
			return false;
		}
		if (a[r][c] != 0) q.push({ r + 1, a[r][c] });
		else q.push({ r + 1, c });
	}
}

//모든 line이 같은 line으로 리턴되는지 확인
bool solve() {
	for (int i = 1; i <= n; ++i)
		if (!pass(i)) return false;
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> h;
	while (m--) {
		int u, v; cin >> u >> v;
		a[u][v] = v+1;
		a[u][v+1] = v;
	}

	//다리 0개
	if (solve()) {
		cout << 0;
		return 0;
	}

	//다리 1개
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j < n; ++j) {
			if (a[i][j] || a[i][j + 1]) continue;
			a[i][j] = j + 1;
			a[i][j + 1] = j;
			if (solve()) {
				cout << 1;
				return 0;
			}
			a[i][j] = a[i][j + 1] = 0;
		}
	}

	//다리 2개
	for (int i = 1; i < h * n; ++i) {
		int ix = i / n + 1, iy = i % n;
		if (a[ix][iy] || a[ix][iy + 1] || iy == 0) continue;
		a[ix][iy] = iy + 1;
		a[ix][iy + 1] = iy;
		for (int j = i + 1; j < h * n; ++j) {
			int jx = j / n + 1, jy = j % n;
			if (a[jx][jy] || a[jx][jy + 1] || jy == 0) continue;
			a[jx][jy] = jy + 1;
			a[jx][jy + 1] = jy;
			if (solve()) {
				cout << 2;
				return 0;
			}
			a[jx][jy] = a[jx][jy + 1] = 0;
		}
		a[ix][iy] = a[ix][iy + 1] = 0;
	}
	
	//다리 3개
	for (int i = 1; i < h*n; ++i) {
		int ix = i / n + 1, iy = i % n;
		if (a[ix][iy] || a[ix][iy + 1] || iy == 0) continue;
		a[ix][iy] = iy + 1;
		a[ix][iy + 1] = iy;
		for (int j = i+1; j < h*n; ++j) {
			int jx = j / n + 1, jy = j % n;
			if (a[jx][jy] || a[jx][jy + 1] || jy == 0) continue;
			a[jx][jy] = jy + 1;
			a[jx][jy + 1] = jy;
			for (int k = j + 1; k < h * n; ++k) {
				int kx = k / n + 1, ky = k % n;
				if (a[kx][ky] || a[kx][ky + 1] || ky == 0) continue;
				a[kx][ky] = ky + 1;
				a[kx][ky + 1] = ky;
				if (solve()) {
					cout << 3;
					return 0;
				}
				a[kx][ky] = a[kx][ky + 1] = 0;
			}
			a[jx][jy] = a[jx][jy + 1] = 0;
		}
		a[ix][iy] = a[ix][iy + 1] = 0;
	}
	cout << -1;

	return 0;
}
//18405
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct S {
	int x, y, cnt;
};

int n, k, s, x, y;
int a[205][205], c[205][205];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
queue<S> q;

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n;
}

int BFS() {
	
	while (!q.empty()) {

		S cur = q.front(); q.pop();
		if (cur.cnt >= s) break;

		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == 0 || (c[nx][ny] == cur.cnt + 1 && a[cur.x][cur.y] < a[nx][ny])) {
				a[nx][ny] = a[cur.x][cur.y];
				c[nx][ny] = cur.cnt + 1;
				q.push({ nx, ny, cur.cnt + 1 });
			}
		}
	}

	return a[x][y];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> a[i][j];
		if (a[i][j] != 0) q.push({ i, j, 0 });
	}

	cin >> s >> x >> y;
	x--, y--;

	cout << BFS() << '\n';

	return 0;
}
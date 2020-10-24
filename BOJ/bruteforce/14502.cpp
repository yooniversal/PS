//14502
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;
vii zero, virus;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int solve(vvi a, vii wall) {
	for (int i = 0; i<wall.size(); ++i) {
		a[wall[i].first][wall[i].second] = 1;
	}

	queue<ii> q;
	for (int i = 0; i < virus.size(); ++i) q.push(virus[i]);
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		a[x][y] = 2;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] != 0) continue;
			q.push({ nx, ny });
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == 0) ++ret;

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << " ";
		cout << '\n';
	}
	cout << "ret:" << ret << '\n';
	cout << '\n';*/

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	vvi a(n, vi(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) zero.push_back({ i, j });
			if (a[i][j] == 2) virus.push_back({ i, j });
		}

	int ret = 0;
	vii wall;
	for (int i = 0; i < zero.size(); ++i) {
		wall.push_back(zero[i]);
		for (int j = i + 1; j < zero.size(); ++j) {
			wall.push_back(zero[j]);
			for (int k = j + 1; k < zero.size(); ++k) {
				wall.push_back(zero[k]);
				ret = max(ret, solve(a, wall));
				wall.pop_back();
			}
			wall.pop_back();
		}
		wall.pop_back();
	}
	cout << ret;

	return 0;
}
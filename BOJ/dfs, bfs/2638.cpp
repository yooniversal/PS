//2638
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int a[101][101], chk[101][101], times, remain;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void BFS() {
	queue<ii> q;
	q.push({ 0,0 });
	memset(chk, 0, sizeof(chk));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (chk[nx][ny] || a[nx][ny]) continue;
			chk[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j] == 0) continue;
		int cnt = 0;
		for (int k = 0; k < 4; ++k) {
			int nx = i + dx[k], ny = j + dy[k];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny]) continue;
			if (!chk[nx][ny]) continue;
			++cnt;
			if (cnt == 2) {
				a[i][j] = 0;
				--remain;
				break;
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
		if (a[i][j]) ++remain;
	}

	while (remain != 0) {
		++times;
		BFS();
	}

	cout << times << '\n';

	return 0;
}
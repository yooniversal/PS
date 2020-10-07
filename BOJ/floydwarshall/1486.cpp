//1486
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll h[26][26];
ll TIME[630][630];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, t, d;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 630; ++i)
		for (int j = 0; j < 630; ++j)
			if (i != j)
				TIME[i][j] = INF;

	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if ('A' <= ch && ch <= 'Z') h[i][j] = ch - 'A';
			else h[i][j] = ch - 'a' + 26;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (OOB(nx, ny)) continue;
				if (abs(h[i][j] - h[nx][ny]) > t) continue;
				if (h[i][j] >= h[nx][ny]) TIME[i * m + j][nx * m + ny] = 1;
				else TIME[i * m + j][nx * m + ny] = (h[i][j] - h[nx][ny]) * (h[i][j] - h[nx][ny]);
			}
		}
	}

	for (int k = 0; k < n * m; ++k) {
		for (int i = 0; i < n * m; ++i) {
			for (int j = 0; j < n * m; ++j) {
				if (TIME[i][j] > TIME[i][k] + TIME[k][j])
					TIME[i][j] = TIME[i][k] + TIME[k][j];
			}
		}
	}

	ll ret = h[0][0];
	for (int i = 0; i < n * m; ++i) {
		if (TIME[0][i] + TIME[i][0] <= d)
			ret = max(ret, h[i / m][i % m]);
	}

	cout << ret;

	return 0;
}
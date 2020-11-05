//10026
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
bool color[101][101];
bool colorWeak[101][101];
bool chk[101][101];
vector<string> a;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,1,-1 };

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

void dfs(int x, int y, char cur) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (color[nx][ny]) continue;
		if (a[nx][ny] != cur) continue;
		color[nx][ny] = true;
		dfs(nx, ny, cur);
	}
}

void dfs2(int x, int y, char cur) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (colorWeak[nx][ny]) continue;
		if (cur != 'B' && a[nx][ny] == 'B') continue;
		if (cur == 'B' && a[nx][ny] != 'B') continue;
		colorWeak[nx][ny] = true;
		dfs2(nx, ny, cur);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		a.push_back(s);
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (color[i][j]) continue;
			color[i][j] = true;
			dfs(i, j, a[i][j]);
			++ret;
		}
	}

	int ret2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (colorWeak[i][j]) continue;
			colorWeak[i][j] = true;
			dfs2(i, j, a[i][j]);
			++ret2;
		}
	}

	cout << ret << ' ' << ret2;

	return 0;
}
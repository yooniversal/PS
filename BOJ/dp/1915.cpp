//1915
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;
int board[MAX][MAX];
int cache[MAX][MAX];
int dx[] = { 0, 1, 1 }, dy[] = { 1, 0, 1 };

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}
int f(int x, int y) {
	if (OOB(x, y)) return -1;
	if (!board[x][y]) return -1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;

	int tmp = INF;
	for (int i = 0; i < 3; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		tmp = min(tmp, f(nx, ny) + 1);
	}
	if (tmp != INF && tmp != 0) ret = tmp;
	else ret = 1;

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j)
			board[i][j] = s[j] - '0';
	}

	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j])
				ret = max(ret, f(i, j));

	cout << ret*ret;

	return 0;
}
//1937
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int board[MAX][MAX];
int cache[MAX][MAX];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}
int f(int x, int y) {
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (board[nx][ny] <= board[x][y]) continue;
		ret = max(ret, f(nx, ny) + 1);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	memset(cache, -1, sizeof(cache));
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ret = max(ret, f(i, j)+1);
		}

	cout << ret;

	return 0;
}
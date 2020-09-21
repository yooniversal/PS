//11048
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[MAX][MAX];
int board[MAX][MAX];
int n, m;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

int f(int x, int y) {
	if (OOB(x, y)) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, f(x - 1, y) + board[x][y]);
	ret = max(ret, f(x, y - 1) + board[x][y]);
	ret = max(ret, f(x - 1, y - 1) + board[x][y]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	cout << f(n - 1, m - 1);

	return 0;
}
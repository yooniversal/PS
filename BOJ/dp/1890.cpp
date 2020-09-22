//1890
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll board[MAX][MAX];
ll cache[MAX][MAX];
int n;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

ll f(int x, int y) {
	if (x == n-1 && y == n-1) return 1;
	if (OOB(x, y)) return 0;
	if (!board[x][y]) return 0;
	ll& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = f(x + board[x][y], y) + f(x, y + board[x][y]);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	cout << f(0, 0);

	return 0;
}
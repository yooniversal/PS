//17090
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int n, m;
int cache[501][501], a[501][501];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int f(int x, int y) {
	if (OOB(x, y)) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = f(x + dx[a[x][y]], y + dy[a[x][y]]);
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
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'U') a[i][j] = 0;
			else if (s[j] == 'R') a[i][j] = 1;
			else if (s[j] == 'D') a[i][j] = 2;
			else a[i][j] = 3;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		ret += f(i, j);
	}
	cout << ret << '\n';

	return 0;
}
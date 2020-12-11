//1577
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

ll cache[101][101];
int dx[] = { 0,1 }, dy[] = { 1,0 };
int n, m;
bool ban[101][101][2];

bool OOB(int x, int y) { return x > n || y > m; }

ll f(int x, int y) {
	if (x == n && y == m) return 1;
	ll& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 2; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (ban[x][y][i]) continue;
		ret += f(nx, ny);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> m >> n;
	int k; cin >> k;
	while (k--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (b == d) ban[b][min(a, c)][0] = true;
		else ban[min(b, d)][a][1] = true;
	}
	cout << f(0, 0) << '\n';

	return 0;
}
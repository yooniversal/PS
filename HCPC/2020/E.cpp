#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,1,-1 };
int n, m, a[3005][3005];

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	while (m--) {
		int x, y, f; cin >> x >> y >> f;
		--x; --y;
		swap(x, y);
		int ret = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = x, ny = y, nf = f, tmp = 0;
			while (!OOB(nx, ny) && nf-a[nx][ny] >= 0) {
				ret = max(ret, ++tmp);
				nf -= a[nx][ny];
				nx += dx[i], ny += dy[i];
			}
		}
		if (ret == 0) cout << "Silver Pantheon\n";
		else cout << ret << '\n';
	}

	return 0;
}
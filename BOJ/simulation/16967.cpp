//16967
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int h, w, x, y, a[301][301], b[1001][1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> h >> w >> x >> y;
	for (int i = 0; i < h + x; ++i) for (int j = 0; j < w + y; ++j) cin >> b[i][j];
	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) a[i][j] = b[i][j];
	for (int i = x; i < h; ++i) for (int j = y; j < w; ++j) a[i][j] -= a[i - x][j - y];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
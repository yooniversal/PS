//10163
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int a[101][101], ret[101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y, w, h; cin >> y >> x >> w >> h;
		for (int nx = x; nx < x + h; ++nx)
			for (int ny = y; ny < y + w; ++ny)
				a[nx][ny] = i;
	}

	for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
		++ret[a[i][j]];
	}

	for (int i = 1; i <= n; ++i)
		cout << ret[i] << '\n';

	return 0;
}
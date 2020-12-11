//2578
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

bool chk[101][101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		for (int nx = x; nx < x + 10; ++nx)
			for (int ny = y; ny < y + 10; ++ny)
				chk[nx][ny] = true;
	}

	int ret = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			ret += chk[i][j];
	cout << ret << '\n';

	return 0;
}
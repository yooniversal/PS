//12759
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int a[4][4];

int solve() {
	for (int i = 1; i <= 3; ++i) {
		bool flag = true;
		for (int j = 1; j <= 3; ++j) {
			if (a[i][j] == 0 || a[i][1] != a[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) return a[i][1];
	}

	for (int i = 1; i <= 3; ++i) {
		bool flag = true;
		for (int j = 1; j <= 3; ++j) {
			if (a[j][i] == 0 || a[1][i] != a[j][i]) {
				flag = false;
				break;
			}
		}
		if (flag) return a[1][i];
	}

	bool flag = true;
	for (int i = 1; i <= 3; ++i) {
		if (a[i][i] == 0 || a[1][1] != a[i][i]) {
			flag = false;
			break;
		}
	}
	if (flag) return a[1][1];

	flag = true;
	for (int i = 1, j=3; i <= 3 && j >= 1; ++i, --j) {
		if (a[i][j] == 0 || a[1][3] != a[i][j]) {
			flag = false;
			break;
		}
	}
	if (flag) return a[1][3];

	return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int fir; cin >> fir;
	for (int i = 0, turn = fir; i < 9; ++i, turn = turn == 1 ? 2 : 1) {
		int x, y; cin >> x >> y;
		a[x][y] = turn;
		if (solve() != 0) {
			cout << solve() << '\n';
			return 0;
		}
	}

	return 0;
}
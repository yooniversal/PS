//2578
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

int a[5][5];
ii n[26];
bool chk[5][5];

bool solve() {
	int ret = 0;
	for (int i = 0; i < 5; ++i) {
		bool flag = true;
		for (int j = 0; j < 5; ++j)
			if (!chk[i][j]) {
				flag = false;
				break;
			}
		if (flag) ++ret;
	}

	for (int i = 0; i < 5; ++i) {
		bool flag = true;
		for (int j = 0; j < 5; ++j)
			if (!chk[j][i]) {
				flag = false;
				break;
			}
		if (flag) ++ret;
	}

	bool flag = true;
	for (int i = 0; i < 5; ++i)
		if (!chk[i][i]) {
			flag = false;
			break;
		}
	if (flag) ++ret;

	flag = true;
	for (int i = 0, j = 4; i < 5 && j >= 0; ++i, --j)
		if (!chk[i][j]) {
			flag = false;
			break;
		}
	if (flag) ++ret;

	if (ret >= 3) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) {
			cin >> a[i][j];
			n[a[i][j]] = { i,j };
		}

	for (int cnt = 1; cnt<=25; ++cnt) {
		int x; cin >> x;
		chk[n[x].first][n[x].second] = true;
		if (solve()) {
			cout << cnt << '\n';
			return 0;
		}
	}

	return 0;
}
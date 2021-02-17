//1080
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int n, m, ret;
char a[51][51], b[51][51];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];

	for (int i = 0; i <= n - 3; ++i) for (int j = 0; j <= m - 3; ++j) {
		if (a[i][j] != b[i][j]) {
			for (int x = i; x < i + 3; ++x) for (int y = j; y < j + 3; ++y) {
				a[x][y] = a[x][y] == '0' ? '1' : '0';
			}
			++ret;
		}
	}

	/*cout << "after:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j];
		}
		cout << '\n';
	}*/
	
	bool flag = true;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j] != b[i][j]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << ret << '\n';
	else cout << -1 << '\n';

	return 0;
}
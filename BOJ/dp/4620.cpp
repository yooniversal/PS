//4620
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

ll board[35][35];
ll cache[35][35];
int n;

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

ll f(int x, int y) {
	if (x == n - 1 && y == n - 1) return 1;
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

	while (1) {
		for (int i = 0; i < 35; ++i) for (int j = 0; j < 35; ++j) {
			cache[i][j] = -1;
			board[i][j] = 0;
		}
		
		cin >> n;
		if (n == -1) break;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			for (int j = 0; j < n; ++j)
				board[i][j] = s[j]-'0';
		}
		cout << f(0, 0) << '\n';
	}

	return 0;
}
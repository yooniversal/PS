//1248
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 9901;

int pSum[15];
int n;
char c[15][15];

bool check(int y) {
	for (int x = y; x >= 1; --x) {
		int cur = pSum[y] - pSum[x - 1];
		if (!((c[x][y] == '+' && cur > 0) || (c[x][y] == '-' && cur < 0) || (c[x][y] == '0' && cur == 0)))
			return false;
	}
	return true;
}

void solve(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= n; ++i)
			cout << pSum[i] - pSum[i - 1] << ' ';
		cout << '\n';
		exit(0);
	}

	for (int i = -10; i <= 10; ++i) {
		pSum[x] = pSum[x - 1] + i;
		if (check(x)) solve(x + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			cin >> c[i][j];

	solve(1);

	return 0;
}
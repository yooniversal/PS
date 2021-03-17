//17779
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, ret = INF;
int a[21][21];

void solve(int x, int y, int d1, int d2) {
	int bound[21][21] = { 0, };
	for (int i = x, j=y; i <= x + d1 && j >= y-d1; ++i, --j) bound[i][j] = 5;
	for (int i = x, j=y; i <= x + d2 && j <= y+d2; ++i, ++j) bound[i][j] = 5;
	for (int i = x+d1, j=y-d1; i <= x + d1 + d2 && j <= y-d1+d2; ++i, ++j) bound[i][j] = 5;
	for (int i = x+d2, j=y+d2; i <= x + d1 + d2 && j >= y-d1+d2; ++i, --j) bound[i][j] = 5;

	for (int i = x + 1; i < x + d1 + d2; ++i) {
		bool flag = true;
		for (int j = 0; j < n; ++j) {
			if (flag) {
				if (bound[i][j] == 5) flag = false;
			}
			else {
				if (bound[i][j] == 5) break;
				bound[i][j] = 5;
			}
		}
	}

	for (int i = 0; i <= x + d1; ++i) {
		for (int j = 0; j <= y; ++j) {
			if (bound[i][j] == 5) break;
			bound[i][j] = 1;
		}
	}
	
	for (int i = 0; i <= x + d2; ++i) {
		for (int j = y+1; j < n; ++j) {
			if (bound[i][j] == 5) continue;
			bound[i][j] = 2;
		}
	}

	for (int i = x+d1; i < n; ++i) {
		for (int j = 0; j < y-d1+d2; ++j) {
			if (bound[i][j] == 5) break;
			bound[i][j] = 3;
		}
	}

	for (int i = x+d2+1; i < n; ++i) {
		for (int j = y-d1+d2; j < n; ++j) {
			if (bound[i][j] == 5) continue;
			bound[i][j] = 4;
		}
	}

	int sum[5] = { 0, };
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (bound[i][j] == 0) sum[4] += a[i][j];
		else sum[bound[i][j] - 1] += a[i][j];
	}

	sort(sum, sum + 5);
	ret = min(ret, sum[4] - sum[0]);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		for (int d1 = 1; d1 <= n - 1; ++d1) for (int d2 = 1; d2 <= n - 1; ++d2) {
			if (i + d1 + d2 >= n || j - d1 < 0 || j + d2 >= n) continue;
			solve(i, j, d1, d2);
		}
	}
	cout << ret << '\n';

	return 0;
}
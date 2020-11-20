#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { 0,0,1,1 }, dy[] = { 0,1,0,1 };
int a[101][101];
int ret;

void solve(int x, int y, vector<vii>& R) {
	vii one, zero;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (a[nx][ny] == 0) zero.push_back({ nx, ny });
		else one.push_back({ nx, ny });
	}

	if (one.size() == 0) return;
	++ret;
	vii tmp;
	if (one.size() == 1) {
		for (int i = 0; i < 2; ++i) {
			a[zero[i].first][zero[i].second] = 1;
			tmp.push_back(zero[i]);
		}
		for (int i = 0; i < 1; ++i) {
			a[one[i].first][one[i].second] = 0;
			tmp.push_back(one[i]);
		}
		R.push_back(tmp);
		solve(x, y, R);
	}
	else if (one.size() == 2) {
		for (int i = 0; i < 2; ++i) {
			a[zero[i].first][zero[i].second] = 1;
			tmp.push_back(zero[i]);
		}
		for (int i = 0; i < 1; ++i) {
			a[one[i].first][one[i].second] = 0;
			tmp.push_back(one[i]);
		}
		R.push_back(tmp);
		solve(x, y, R);
	}
	else {
		for (int i = 0; i < 3; ++i) {
			a[one[i].first][one[i].second] = 0;
			tmp.push_back(one[i]);
		}
		R.push_back(tmp);
		solve(x, y, R);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ret = 0;
		vector<vii> R;
		for (int i = 0; i < 101; ++i) for (int j = 0; j < 101; ++j) a[i][j] = 0;
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			string s; cin >> s;
			for (int j = 1; j <= m; ++j)
				a[i][j] = s[j - 1] - '0';
		}

		for (int i = 1; i <= n-1; i += 2)
			for (int j = 1; j <= m-1; j += 2)
				solve(i, j, R);

		if (m % 2) {
			for (int i = 1; i <= n - 1; i += 2)
				solve(i, m - 1, R);
		}
		if (n % 2) {
			for (int i = 1; i <= m - 1; i += 2)
				solve(n - 1, i, R);
		}
		solve(n - 1, m - 1, R);

		cout << ret << '\n';
		for (int i = 0; i < ret; ++i) {
			for (int j = 0; j < R[i].size(); ++j)
				cout << R[i][j].first << ' ' << R[i][j].second << ' ';
			cout << '\n';
		}
	}

	return 0;
}
//16935
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int N, M, r;
int a[101][101];
bool flag;

void query(int d) {
	int n=N, m=M;
	if (flag) swap(n, m);

	int ret[101][101] = { 0, };
	if (d == 1) {
		for (int i = 0; i < m; ++i) for (int j = n - 1, k = 0; j >= 0 && k < n; --j, ++k) {
			ret[k][i] = a[j][i];
		}
	}
	else if (d == 2) {
		for (int i = 0; i < n; ++i) for (int j = 0, k = m - 1; j < m && k >= 0; ++j, --k) {
			ret[i][k] = a[i][j];
		}
	}
	else if (d == 3) {
		for (int i = 0, c = n - 1; i < n && c >= 0; ++i, --c) for (int j = 0, r = 0; j < m && r < m; ++j, ++r) {
			ret[r][c] = a[i][j];
		}
	}
	else if (d == 4) {
		for (int i = 0, c = 0; i < n && c < n; ++i, ++c) for (int j = m - 1, r = 0; j >= 0 && r < m; --j, ++r) {
			ret[r][c] = a[i][j];
		}
	}
	else if (d == 5) {
		for (int i = 0; i < n / 2; ++i) for (int j = 0; j < m / 2; ++j) ret[i][j + m / 2] = a[i][j];
		for (int i = 0; i < n / 2; ++i) for (int j = m / 2; j < m; ++j) ret[i + n / 2][j] = a[i][j];
		for (int i = n / 2; i < n; ++i) for (int j = m / 2; j < m; ++j) ret[i][j - m / 2] = a[i][j];
		for (int i = n / 2; i < n; ++i) for (int j = 0; j < m / 2; ++j) ret[i - n / 2][j] = a[i][j];
	}
	else {
		for (int i = 0; i < n / 2; ++i) for (int j = 0; j < m / 2; ++j) ret[i+n/2][j] = a[i][j];
		for (int i = 0; i < n / 2; ++i) for (int j = m / 2; j < m; ++j) ret[i][j-m/2] = a[i][j];
		for (int i = n / 2; i < n; ++i) for (int j = m / 2; j < m; ++j) ret[i-n/2][j] = a[i][j];
		for (int i = n / 2; i < n; ++i) for (int j = 0; j < m / 2; ++j) ret[i][j+m/2] = a[i][j];
	}

	if (d == 3 || d == 4) swap(n, m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = ret[i][j];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> r;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> a[i][j];

	int n, m;
	if (flag) n = M, m = N;
	else n = N, m = M;

	for (int i = 0; i < r; ++i) {
		int d; cin >> d;
		query(d);
		if (d == 3 || d == 4) flag = !flag;
	}
	
	int R = n, C = m;
	if (flag) swap(R, C);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			if (a[i][j] != 0)
				cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
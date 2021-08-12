// 1913
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int a[1005][1005], N;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

void solve(int x, int y, int n) {
	int cx = x, cy = y, cnt = n*n;
	a[cx][cy] = cnt;

	if (n == 1) return;

	for (int i = 0; i < 4; ++i) {
		int times = i == 3 ? n - 2 : n - 1;
		for (int j = 0; j < times; ++j) {
			cx += dx[i], cy += dy[i];
			a[cx][cy] = --cnt;
		}
	}

	solve(x + 1, y + 1, n - 2);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v; cin >> N >> v;

	solve(0, 0, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	int x = -1, y = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i][j] == v) {
				cout << i+1 << ' ' << j+1 << '\n';
				return 0;
			}
		}
	}

	return 0;
}
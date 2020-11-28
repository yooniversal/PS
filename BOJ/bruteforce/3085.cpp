//3085
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
vector<string> a;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int cnt(int x, int y) {
	int ret = 0, tmp = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (i == 2) tmp = 1;
		if (OOB(nx, ny)) continue;
		while (a[x][y] == a[nx][ny]) {
			++tmp;
			nx += dx[i], ny += dy[i];
			if (OOB(nx, ny)) break;
		}
		if(tmp != 1) ret = max(ret, tmp);
	}
	return ret;
}

int solve(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		swap(a[x][y], a[nx][ny]);
		ret = max(ret, max(cnt(x, y), cnt(nx, ny)));
		swap(a[x][y], a[nx][ny]);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		a.push_back(s);
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret = max(ret, solve(i, j));
		}
	}

	cout << ret << '\n';

	return 0;
}
//16946
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, uni[MAX], cost[MAX], a[1001][1001], ret[1001][1001];
bool chk[MAX];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void makeUnion(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) uni[a] = b;
	else uni[b] = a;
}

int f(int x, int y) { return x * m + y; }

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX; ++i) uni[i] = i;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j)
			a[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		for (int d = 0; d < 4; ++d) {
			int nx = i + dx[d], ny = j + dy[d];
			if (OOB(nx, ny)) continue;
			if (a[i][j] || a[nx][ny]) continue;
			makeUnion(f(i, j), f(nx, ny));
		}
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j]) continue;
		++cost[find(f(i, j))];
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (a[i][j] == 0) continue;
		int sum = 1;
		vi tmp;
		for (int d = 0; d < 4; ++d) {
			int nx = i + dx[d], ny = j + dy[d];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] || chk[find(f(nx, ny))]) continue;
			chk[find(f(nx, ny))] = true;
			tmp.push_back(find(f(nx, ny)));
			sum += cost[find(f(nx, ny))];
		}
		ret[i][j] = sum%10;
		for (int t : tmp) chk[t] = false;
		tmp.clear();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << ret[i][j];
		cout << '\n';
	}
	cout << '\n';

	return 0;
}
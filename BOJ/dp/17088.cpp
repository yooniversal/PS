//17088
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int dx[] = { 1,1,1,-1,-1,-1,0,0,0 }, dy[] = { 1,-1,0,1,-1,0,1,-1,0 }, dt[] = { 1,-1,0 };
int add[] = { 2,2,1,2,2,1,1,1,0 };
int cache[100001][9][3];
int n;
vi a;

int f(int cur, int t, int prev) {
	if (cur >= n) return 0;
	int& ret = cache[cur][t][prev];
	if (ret != -1) return ret;
	ret = INF;
	int d = (a[0] + dx[t]) - (a[1] + dy[t]);
	for (int i = 0; i < 3; ++i) {
		if (a[cur - 1] + dt[prev] - (a[cur] + dt[i]) != d) continue;
		if (i != 2) ret = min(ret, f(cur + 1, t, i) + 1);
		else ret = min(ret, f(cur + 1, t, i));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int ret = INF;
	for (int i = 0; i < 9; ++i)
		ret = min(ret, f(2, i, i%3) + add[i]);
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}
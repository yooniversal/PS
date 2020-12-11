//12026
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int cache[1001][3];
int n;
vi a;

int f(int now, int cur) {
	if (now == n - 1) return 0;
	int& ret = cache[now][cur];
	if (ret != -1) return ret;
	ret = INF;
	int next = (cur + 1) % 3;
	for (int i = now + 1; i < n; ++i)
		if (a[i] == next) ret = min(ret, f(i, next) + (i - now) * (i - now));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	a.resize(n);
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') a[i] = 0;
		else if (s[i] == 'O') a[i] = 1;
		else a[i] = 2;
	}

	int ret = f(0, 0);
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}
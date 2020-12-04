//5721
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int m, n;
int a[MAX];
ll cache[MAX];

ll f(int i) {
	if (i >= n*m) return 0;
	ll& ret = cache[i];
	if (ret != -1) return ret;
	ret = 0;
	int x = i / n, y = i % n;
	if (y == n-1)
		ret = max(ret, max(f((x+2)*n), f((x+3)*n)) + a[i]);
	else if (y == n-2)
		ret = max(ret, max(f(i+1), max(f((x+2)*n), f((x+3)*n)) + a[i]));
	else
		ret = max(ret, max(f(i+1), f(i+2) + a[i]));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n * m; ++i) cin >> a[i];

		cout << max(f(0), f(n)) << '\n';
	}

	return 0;
}
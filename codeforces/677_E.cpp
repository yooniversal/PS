#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[21][21];

ll f(int n, int m) {
	if (n == 1) return 1;
	if (m == 0 || m == n) return 1;
	ll& ret = cache[n][m];
	if (ret != -1) return ret;
	ret = 0;
	ret = f(n - 1, m - 1) + f(n - 1, m);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	ll tmp = 1;
	for (int i = 1; i <= n / 2-1; ++i)
		tmp *= i;
	cout << f(n, n / 2) * tmp * tmp / 2;

	return 0;
}
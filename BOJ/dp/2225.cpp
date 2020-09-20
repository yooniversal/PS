//2225
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 205
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[MAX][MAX];

ll f(int n, int k) {
	if (k == 0) {
		if (n == 0) return 1;
		else return 0;
	}
	ll& ret = cache[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; ++i)
		ret += f(n - i, k - 1) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	int n, k; cin >> n >> k;
	cout << f(n, k);

	return 0;
}
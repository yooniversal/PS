//15988
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000009
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[MAX];

ll f(int n) {
	//cout << "n:" << n << '\n';
	if (n < 0) return 0;
	if (n == 0) return 1;
	
	ll& ret = cache[n];
	if (ret != -1) return ret;

	ret = (f(n - 3) % MOD + f(n - 2) % MOD + f(n - 1) % MOD + MOD) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << f(n) << '\n';
	}

	return 0;
}
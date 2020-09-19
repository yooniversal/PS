//15990
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000009
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[MAX][4];

ll f(int cur, int prev) {
	if (cur < 0) return 0;
	if (cur == 0) return 1;
	ll& ret = cache[cur][prev];
	if (ret != -1) return ret;
	
	ret = 0;
	if (prev != 1) ret += f(cur - 1, 1) % MOD;
	if (prev != 2) ret += f(cur - 2, 2) % MOD;
	if (prev != 3) ret += f(cur - 3, 3) % MOD;
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
		cout << f(n, 0) << '\n';
	}

	return 0;
}
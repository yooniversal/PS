//1788
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[1000001];

ll f(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	ll& ret = cache[n];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(n - 1) % MOD;
	ret += f(n - 2) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	if (n == 0) cout << 0;
	else if (n < 0 && (abs(n) % 2 == 0)) cout << -1;
	else cout << 1;
	cout << '\n';
	cout << f(abs(n));

	return 0;
}
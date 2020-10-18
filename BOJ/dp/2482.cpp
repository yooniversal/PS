//2482
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000003
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[1001][1001];
int n, k;

ll f(int cur, int time) {
	if (cur <= 0) return 0;
	if (time == 1) return cur;
	ll& ret = cache[cur][time];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(cur - 2, time - 1) % MOD;
	ret += f(cur - 1, time) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	ll ret = 0;
	if (k == 1) cout << n;
	else {
		ret += f(n - 3, k - 1) % MOD;
		ret += f(n - 1, k) % MOD;
		ret %= MOD;
		cout << ret;
	}

	return 0;
}
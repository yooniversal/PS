//10422
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[5001][2502];
int n;

ll f(int a, int sum) {
	if (sum < 0) return 0;
	if (sum > n / 2 + 1) return 0;
	if (a == 0) {
		if (sum == 0) return 1;
		return 0;
	}
	ll& ret = cache[a][sum];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(a - 1, sum + 1) % MOD + f(a - 1, sum - 1) % MOD;
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
		cin >> n;
		cout << f(n, 0) << '\n';
	}

	return 0;
}
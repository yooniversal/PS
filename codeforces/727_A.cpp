#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k; cin >> k;
	while (k--) {
		ll n, x, t; cin >> n >> x >> t;
		ll tx = t / x;
		ll ret = 0;
		if (n >= tx) ret = (tx - 1) * tx / 2 + (n - tx) * tx;
		else ret = (n - 1) * n / 2;
		cout << ret  << '\n';
	}

	return 0;
}
//13702
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, k;
ll sum;
vi a;

ll binary_search(ll l, ll r) {
	ll ret = 0;
	while (l <= r) {
		ll m = (l + r) / 2, tmp = 0;
		for (int& f : a) {
			tmp += f / m;
		}
		printf("l:%lld m:%lld r:%lld tmp:%lld ret:%lld\n", l, m, r, tmp, ret);
		if (tmp >= k) {
			l = m + 1;
			
			ret = m;
		}
		else {
			r = m - 1;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << binary_search(0, INT_MAX - 1);

	return 0;
}
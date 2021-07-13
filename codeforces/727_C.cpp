#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

ll n, k, x;

ll binary_search(ll l, ll r, ll cur) {
	ll ret = r;
	while (l <= r) {
		ll m = (l + r) / 2;
		ll target = cur / m;
		if (cur % m != 0) ++target;
		if (target > x) {
			l = m + 1;
		}
		else {
			r = m - 1;
			ret = m;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<ll> b;
	for (int i = 0; i < n - 1; ++i) {
		ll diff = a[i + 1] - a[i];
		if (diff > x) b.emplace_back(diff);
	}
	sort(b.begin(), b.end());

	ll ret = b.size()+1;
	for (int i = 0; i < b.size(); ++i) {
		ll maxx = b[i] / (k+1);
		if (b[i] % (k+1)) ++maxx;
		if (maxx > x || k == 0) break;
		ll tmp = binary_search(2, k + 1, b[i]);
		k -= (tmp - 1);
		--ret;
	}
	cout << ret << '\n';

	return 0;
}
//1300
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi a;
int n, k;

ll binary_search(ll l, ll r) {
	ll ret = 1;
	while (l <= r) {
		ll m = (l + r) / 2, tmp = 0;
		for (int i = 1; i <= n; ++i)
			tmp += lower_bound(a.begin(), a.end(), m / i) - a.begin();
		if (tmp < k)
			l = m + 1;
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

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) a[i] = i;
	cout << binary_search(1, 1000000000);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;



int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vector<ll> a;
		ll tmp = n;
		for (ll i = 2; i * i <= n; ++i) {
			if (tmp % i == 0) {
				a.push_back(i);
				tmp /= i;
				i = 1;
				
			}
		}
		sort(a.begin(), a.end());
		ll prev = -1, cur = 1, ret = 1, rret = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (prev != a[i]) {
				cur = 1;
				prev = a[i];
			}
			else {
				if (ret < ++cur) {
					ret = cur;
					rret = a[i];
				}
			}
		}
		cout << ret << '\n';
		if (ret == 1) cout << n << '\n';
		else {
			for (int i = 0; i < ret - 1; ++i) {
				cout << rret << ' ';
				n /= rret;
			}
			cout << n << '\n';
		}
	}

	return 0;
}
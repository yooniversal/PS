//15486
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

ll S;

ll binary_search(ll l, ll r) {
	ll ret = 0;
	while (l < r) {
		ll sum = 0, m = (l + r) / 2;
		ll tmp = m * (m + 1) / 2;
		if (tmp <= S) {
			l = m + 1;
			ret = m;
		}
		else r = m;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> S;
	cout << binary_search(1, 100001);

	return 0;
}
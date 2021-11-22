//23323
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

	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		ll two_power = 1;
		int cnt = 0;
		while (n > two_power) {
			two_power <<= 1;
			++cnt;
		}
		if (n == two_power) ++cnt;
		cout << cnt + m << '\n';
	}

	return 0;
}
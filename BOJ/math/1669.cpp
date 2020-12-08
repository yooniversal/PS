//1669
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int X, Y, x; cin >> X >> Y;
	x = Y - X;

	if (x <= 3) {
		cout << x << '\n';
		return 0;
	}

	for (int i = 1; i <= 46341; ++i) {
		ll l = 1LL * i * i, r = 1LL * (i + 1) * (i + 1);
		if (l <= x && x < r) {
			if (l == x) {
				cout << 2 * i - 1 << '\n';
				return 0;
			}
			else if(x<=l+i){
				cout << 2 * i << '\n';
				return 0;
			}
			else {
				cout << 2 * i + 1 << '\n';
				return 0;
			}
		}
	}

	return 0;
}
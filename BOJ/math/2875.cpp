//2875
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;
	if (n % 2) --n, --k;
	int a = min(n / 2, m), tmp = -1;
	if (n / 2 > m) {
		tmp = k - (n / 2 - a) * 2;
		if (tmp < 0) {
			cout << a << '\n';
		}
		else {
			if (tmp % 3) tmp = tmp / 3 + 1;
			else tmp = tmp / 3;
			cout << a - tmp << '\n';
		}
	}
	else if (n / 2 < m) {
		if (k < m - a) {
			cout << a << '\n';
		}
		else {
			tmp = k - (m - a);
			if (tmp % 3) tmp = tmp / 3 + 1;
			else tmp = tmp / 3;
			cout << a - tmp << '\n';
		}
	}
	else {
		tmp = k;
		if (tmp % 3) tmp = tmp / 3 + 1;
		else tmp = tmp / 3;
		cout << a - tmp << '\n';
	}

	return 0;
}
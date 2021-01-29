//17087
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

int GCD(int a, int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s; cin >> n >> s;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		if (t <= s) a[i] = s - t;
		else a[i] = t - s;
	}

	int ret = n>1 ? GCD(a[0], a[1]) : a[0];
	for (int i = 2; i < n; ++i) ret = GCD(ret, a[i]);
	cout << ret << '\n';

	return 0;
}
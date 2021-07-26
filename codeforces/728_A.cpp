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
		vi a;
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) a.emplace_back(i);
		for (int i = 0; i < n - 1; i+=2) {
			if (i == n - 2 && (n % 2 == 1)) {
				break;
			}
			swap(a[i], a[i + 1]);
		}

		if (n%2) swap(a[n - 3], a[n - 1]);

		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
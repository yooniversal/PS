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
		int n; cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll minn = a[0], maxx = a[n - 1], sum = 0;
		for (int i = 1; i < n; ++i) sum += maxx - a[i];
		if (sum >= minn) {
			cout << sum - minn << '\n';
		}
		else {
			sum = minn - sum;
			sum %= n - 1;
			if (sum == 0) cout << 0 << '\n';
			else cout << n - 1 - sum << '\n';
		}

	}

	return 0;
}
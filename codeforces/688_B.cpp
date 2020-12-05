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
		vi a(n+1);
		ll sum = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 2; i <= n; ++i) {
			sum += abs(a[i] - a[i-1]);
		}

		int maxx = max(abs(a[2]-a[1]), abs(a[n]-a[n-1]));
		for (int i = 2; i < n; ++i) {
			maxx = max(maxx, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
		}
		cout << sum - maxx << '\n';
	}

	return 0;
}
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
		int n, k; cin >> n >> k;
		vi a(n * k);
		for (int i = 0; i < n * k; ++i) cin >> a[i];
		ll ret = 0;
		if (n == 1) {
			for (int i = 0; i < n * k; ++i) ret += a[i];
		}
		else if (n == 2) {
			for (int i = 0; i < n * k; i += 2) ret += a[i];
		}
		else {
			if (n % 2 == 0) {
				for (int i = n * k - 1 - n / 2, cnt = 0; i >= 0, cnt < k; i -= n / 2 + 1, ++cnt) {
					ret += a[i];
				}
			}
			else {
				for (int i = n * k - 1 - n / 2, cnt = 0; i >= 0, cnt < k; i -= n / 2 + 1, ++cnt) {
					ret += a[i];
				}
			}
		}
		cout << ret << '\n';
	}

	return 0;
}
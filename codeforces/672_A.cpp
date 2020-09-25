#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		bool ret = true;
		for (int i = 0; i < n-1; ++i) {
			if (a[i] <= a[i + 1]) {
				ret = 0;
				break;
			}
		}

		if (ret) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}
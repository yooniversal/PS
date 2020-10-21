#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
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
		vi a(n);
		int maxx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			maxx = max(maxx, a[i]);
		}
		int ret = -1;
		if (n > 2) {
			for (int i = 0; i < n; ++i)
				if (a[i] == maxx)
					if (i > 0 && a[i - 1] < a[i]) {
						ret = i;
						break;
					}
					else if (i+1 < n && a[i] > a[i + 1]) {
						ret = i;
						break;
					}
		}
		else {
			if (a[0] > a[1]) ret = 0;
			else if (a[0] < a[1]) ret = 1;
		}
		
		if (ret != -1) cout << ret+1 << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}
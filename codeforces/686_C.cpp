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

int chk[200001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		int n; cin >> n;
		vi a(n);
		int prev = -1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (chk[a[i]] == 0 || prev != a[i]) ++chk[a[i]];
			prev = a[i];
		}

		for (int i = 1; i <= n; ++i) {
			if (chk[i] == 0) continue;
			if (a[0] == i && a[n - 1] == i) --chk[i];
			else ++chk[i];
		}
		if (a[0] != a[n - 1]) --chk[a[0]], --chk[a[n - 1]];

		int ret = INF;
		for (int i = 1; i <= n; ++i) {
			if (chk[i] == 0) continue;
			ret = min(ret, chk[i]);
		}
		if (ret != INF) cout << ret << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}
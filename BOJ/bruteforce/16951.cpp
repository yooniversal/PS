//16951
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	int ret = n;
	for (int st = 1; st <= 1000; ++st) {
		int tmp = 0, cur = st;
		for (int i = 0; i < n; ++i, cur += k)
			if (cur != a[i]) ++tmp;
		ret = min(ret, tmp);
	}
	cout << ret << '\n';

	return 0;
}
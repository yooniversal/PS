#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

ii solve(vi& a) {
	if (a.size() == 1) return { -1, -1 };

	for (int i = 0; i < a.size()-1; ) {
		if (a[i] >= a[i + 1]) ++i;
		else {
			++a[i];
			return { 1, i };
		}
	}

	return { -1, -1 };
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int cnt = 0, ret = -1;
		while (1) {
			auto cur = solve(a);
			if (cur.first != -1) {
				cnt += cur.first;
				if (cnt >= k) {
					ret = cur.second+1;
					break;
				}
			}
			else
				break;
		}

		cout << ret << '\n';	
	}

	return 0;
}
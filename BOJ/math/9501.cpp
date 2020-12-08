//9501
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;



int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, d, ret=0; cin >> n >> d;
		for (int i = 0; i < n; ++i) {
			double v, f, c; cin >> v >> f >> c;
			if (v * f / c >= d) ++ret;
		}
		cout << ret << '\n';
	}

	return 0;
}
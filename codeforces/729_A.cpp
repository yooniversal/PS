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
		int n; cin >> n;
		int o = 0, e = 0;
		for (int i = 0; i < 2*n; ++i) {
			int tmp; cin >> tmp;
			if (tmp % 2) ++o;
			else ++e;
		}
		if (o != e) cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}
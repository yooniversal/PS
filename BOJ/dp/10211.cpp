//10211
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
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
		//O(n^2)
		/*vi a(n), pSum(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			pSum[i+1] = pSum[i] + a[i];
		}

		int ret = -INF;
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j <= n; ++j)
				ret = max(ret, pSum[j] - pSum[i]);
		cout << ret << '\n';*/

		//O(n)
		int pSum1 = 0, pSum2 = 0, ret = -INF;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			pSum1 += x;
			ret = max(ret, pSum1 - pSum2);
			pSum2 = min(pSum1, pSum2);
		}
		cout << ret << '\n';
	}

	return 0;
}
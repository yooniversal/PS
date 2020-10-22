//10211
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
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
		vi a(n), pSum(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			pSum[i+1] = pSum[i] + a[i];
		}

		int ret = -INF;
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j <= n; ++j)
				ret = max(ret, pSum[j] - pSum[i]);
		cout << ret << '\n';
	}

	return 0;
}
// 2231
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

	int n; cin >> n;
	
	int ret = 0;
	for (int i = 0; i <= n; ++i) {
		int sum = i, cur = i;
		while (cur != 0) {
			sum += cur % 10;
			cur /= 10;
		}
		if (sum == n) {
			ret = i;
			break;
		}
	}

	cout << ret << '\n';

	return 0;
}
//14469
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 1234567;

vii a;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int A, B; cin >> A >> B;
		a.push_back({ A, B });
	}
	sort(a.begin(), a.end());

	int ret = a[0].first + a[0].second;
	for (int i = 1; i < n; ++i) {
		if (ret < a[i].first) {
			ret = a[i].first + a[i].second;
		}
		else {
			ret += a[i].second;
		}
	}
	cout << ret << '\n';

	return 0;
}
//6131
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, ret = 0; cin >> n;
	for (int b = 1; b <= 500; ++b) for (int a = b; a <= 500; ++a) {
		if (a * a == b * b + n) ++ret;
	}
	cout << ret << '\n';

	return 0;
}
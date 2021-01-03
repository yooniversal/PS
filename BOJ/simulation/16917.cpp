//16917
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, x, y, ret=0; cin >> a >> b >> c >> x >> y;
	if (min(x, y)) {
		if (a + b > c * 2) {
			ret += c * 2 * min(x, y);
		}
		else {
			ret += (a + b) * min(x, y);
		}
	}
	
	int remain = max(x, y) - min(x, y);
	if (x > y) {
		if (a > c * 2) {
			ret += c * 2 * remain;
		}
		else {
			ret += a * remain;
		}
	}
	else {
		if (b > c * 2) {
			ret += c * 2 * remain;
		}
		else {
			ret += b * remain;
		}
	}

	cout << ret << '\n';

	return 0;
}
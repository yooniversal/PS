//1057
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 9901;

bool isMatch(int a, int b) {
	a = a % 2 ? a + 1 : a;
	b = b % 2 ? b + 1 : b;
	return a == b;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, ret = 1; cin >> n >> a >> b;
	
	while (!isMatch(a, b)) {
		++ret;
		a = a % 2 ? (a + 1) / 2 : a / 2;
		b = b % 2 ? (b + 1) / 2 : b / 2;
	}

	if (ret != 0) cout << ret << '\n';
	else cout << -1 << '\n';

	return 0;
}
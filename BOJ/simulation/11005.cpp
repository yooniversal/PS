//11005
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, b; cin >> n >> b;
	string ret = "";

	while (n >= b) {
		int remainder = n % b;
		if (remainder >= 10) ret += remainder + 'A' - 10;
		else ret += remainder + '0';
		n = n / b;
	}
	if (n >= 10) ret += n + 'A' - 10;
	else ret += n + '0';

	reverse(ret.begin(), ret.end());
	cout << ret << '\n';

	return 0;
}
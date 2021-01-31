//2745
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

	string n; int b; cin >> n >> b;

	int ret = 0;
	for (int i = n.size() - 1, mul = 1; i >= 0; --i, mul *= b) {
		if ('0' <= n[i] && n[i] <= '9') ret += (n[i] - '0') * mul;
		else ret += (n[i] - 'A' + 10) * mul;
	}

	cout << ret << '\n';

	return 0;
}
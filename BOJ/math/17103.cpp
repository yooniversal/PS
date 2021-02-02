//17103
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

bool prime[1000001];

void e() {
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i <= 1000; ++i) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= 1000000; j += i) {
			prime[j] = false;
		}
	}
	prime[1] = false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	e();

	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		int ret = 0;
		for (int i = 1; i <= a/2; ++i) {
			if (prime[i] && prime[a - i]) ++ret;
		}
		cout << ret << '\n';
	}

	return 0;
}
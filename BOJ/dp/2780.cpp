//2780
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

vi a[10];
int n;
int cache[10][1001];

int f(int cur, int len) {
	if (len == n) return 1;
	int& ret = cache[cur][len];
	if (ret != -1) return ret;
	ret = 0;
	for (int next : a[cur]) {
		ret = (ret + f(next, len + 1)) % MOD;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	a[1].push_back(2);
	a[1].push_back(4);
	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(5);
	a[3].push_back(2);
	a[3].push_back(6);
	a[4].push_back(1);
	a[4].push_back(5);
	a[4].push_back(7);
	a[5].push_back(2);
	a[5].push_back(4);
	a[5].push_back(6);
	a[5].push_back(8);
	a[6].push_back(3);
	a[6].push_back(5);
	a[6].push_back(9);
	a[7].push_back(0);
	a[7].push_back(4);
	a[7].push_back(8);
	a[8].push_back(5);
	a[8].push_back(7);
	a[8].push_back(9);
	a[9].push_back(6);
	a[9].push_back(8);
	a[0].push_back(7);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		int ret = 0;
		for (int i = 0; i <= 9; ++i)
			ret = (ret + f(i, 1)) % MOD;
		cout << ret << '\n';
	}

	return 0;
}
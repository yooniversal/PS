//9084
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[10001][21];
vi coin;

int f(int n, int p) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	int& ret = cache[n][p];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = p; i < coin.size(); ++i)
		ret += f(n - coin[i], i);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		coin.clear();
		int n; cin >> n;
		coin.resize(n);
		for (int i = 0; i < n; ++i) cin >> coin[i];
		int m; cin >> m;
		cout << f(m, 0) << '\n';
	}

	return 0;
}
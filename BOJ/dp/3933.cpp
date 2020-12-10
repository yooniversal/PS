//3933
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int cache[32769][185][5];
int n;

int f(int sum, int cur, int len) {
	if (len < 0 || cur <= 0) return 0;
	if (sum == 0) return 1;
	int& ret = cache[sum][cur][len];
	if (ret != -1) return ret;
	ret = 0;
	if(sum-cur*cur >= 0) ret += f(sum - cur*cur, cur, len - 1);
	ret += f(sum, cur - 1, len);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	while (1) {
		cin >> n;
		if (n == 0) break;
		int ret = 0;
		for (int i = 1; i*i <= n; ++i)
			ret += f(n-i*i, i, 3);
		cout << ret << '\n';
	}

	return 0;
}
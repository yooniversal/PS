//1562
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int cache[101][1<<10][11];

int f(int cur, int chk, int ed) {
	if (cur == n) {
		if (chk < (1 << 10) - 1) return 0;
		return 1;
	}
	int& ret = cache[cur][chk][ed];
	if (ret != -1) return ret;
	ret = 0;
	for (int ned : {ed - 1, ed + 1}) {
		if (ned < 0 || ned >= 10) continue;
		ret += f(cur + 1, chk | (1 << ned), ned) % MOD;
	}
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	ll ret = 0;
	for (int i = 1; i <= 9; ++i) {
		ret += f(1, 1<<i, i);
		ret %= MOD;
	}
	cout << ret;

	return 0;
}
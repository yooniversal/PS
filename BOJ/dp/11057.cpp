//11057
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int cache[1001][10];

int f(int cur, int prev) {
	if (cur == n-1) return 1;
	int& ret = cache[cur][prev];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= 9; ++i) {
		if (prev > i) continue;
		ret += f(cur + 1, i) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	
	int ret = 0;
	for (int i = 0; i <= 9; ++i) {
		ret += f(0, i) % MOD;
		ret %= MOD;
	}
	cout << ret;

	return 0;
}
//15624
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[1000001];
int n;

ll f(int i) {
	if (i <= 0) return 0;
	if (i == 1 || i == 2) return 1;
	ll& ret = cache[i];
	if (ret != -1) return ret;
	ret = (f(i - 1) + f(i - 2)) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << f(n);

	return 0;
}
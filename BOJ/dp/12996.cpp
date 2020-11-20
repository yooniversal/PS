//12996
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[51][51][51][51];

ll f(int s, int a, int b, int c) {
	if (s < 0 || a < 0 || b < 0 || c < 0) return 0;
	if (a == 0 && b == 0 && c == 0) {
		if (s>0) return 0;
		return 1;
	}
	ll& ret = cache[s][a][b][c];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(s - 1, a - 1, b - 1, c - 1) % MOD;
	ret %= MOD;
	ret += f(s - 1, a - 1, b - 1, c) % MOD;
	ret %= MOD;
	ret += f(s - 1, a - 1, b, c - 1) % MOD;
	ret %= MOD;
	ret += f(s - 1, a, b - 1, c - 1) % MOD;
	ret %= MOD;
	ret += f(s - 1, a - 1, b, c) % MOD;
	ret %= MOD;
	ret += f(s - 1, a, b - 1, c) % MOD;
	ret %= MOD;
	ret += f(s - 1, a, b, c - 1) % MOD;
	ret %= MOD;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int s, a, b, c; cin >> s >> a >> b >> c;
	cout << f(s, a, b, c);

	return 0;
}
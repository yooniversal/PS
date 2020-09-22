//15829
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
#define MOD 1234567891
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll pow(int a, int n) {
	if (n == 0) return 1;
	ll ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret *= a;
		ret %= MOD;
	}
	return ret % MOD;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;
	
	ll ret = 0;
	for (int i = 0; i < s.size(); ++i) {
		ret += (s[i] - 'a' + 1) * pow(31, i);
		ret %= MOD;
	}
	cout << ret;

	return 0;
}
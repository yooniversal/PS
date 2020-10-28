//1351
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll n, p, q;
map<ll, ll> cache;

ll f(ll cur) {
	if (cur == 0) return 1;
	ll& ret = cache[cur];
	if (ret != 0) return ret;
	ret = 0;
	ret = f(cur / p) + f(cur / q);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> p >> q;
	cout << f(n);

	return 0;
}
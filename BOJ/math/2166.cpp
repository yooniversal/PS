//2166

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> xy;

ll CCW(pll a, pll b, pll c) {
	ll ans = (a.first * b.second + b.first * c.second + c.first * a.second);
	ans -= (a.first * c.second + b.first * a.second + c.first * b.second);
	return ans;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	ll x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		xy.push_back({ x, y });
	}

	ll ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		ans += CCW(xy[0], xy[i], xy[i+1]);
	}

	ans = abs(ans);
	cout << ans / 2;
	if (ans % 2) cout << ".5";
	else cout << ".0";

	return 0;
}
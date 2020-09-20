#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;

ll f(ll n) {
	ll ret = 1;
	queue<pair<ll, ll>> q;
	q.push({ 3, 6 });
	n--;

	while (n > 0) {
		pair<ll, ll> cur = q.front(); q.pop();
		n -= cur.second;
		if (n >= 0) ret++;
		q.push({ cur.first * 2 + 1, cur.second * 2 + (cur.first + 1) * (cur.first + 1) });
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << f(n) << '\n';
	}

	return 0;
}
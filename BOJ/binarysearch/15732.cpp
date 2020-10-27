//15732
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

struct R {
	ll a, b, c;
	R() : a(-1), b(-1), c(-1) {}
};

ll n, k, d;
vector<R> room;

ll binary_search(ll l, ll r) {
	ll ret = 0;
	while (l < r) {
		ll m = (l + r) / 2, tmp = 0;
		for (auto& cur : room) {
			if (m < cur.a) continue;
			tmp += (min(m, cur.b) - cur.a) / cur.c + 1;
		}
		if (tmp < d)
			l = m + 1;
		else {
			r = m;
			ret = m;
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> d;
	room.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> room[i].a >> room[i].b >> room[i].c;
	}
	cout << binary_search(1, 1000000);

	return 0;
}
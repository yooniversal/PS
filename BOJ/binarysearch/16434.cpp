//16434
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct R {
	ll t, a, h;
};

ll n, atk;
R room[123457];

ll binary_search(ll l, ll r) {
	ll ret = 0;
	while (l < r) {
		ll sum = 0, m = (l + r) / 2;
		ll tmp = 0, curATK = atk, curHP = m;
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if (room[i].t == 1) {
				ll tmp = room[i].h / curATK;
				if (room[i].h % curATK == 0) --tmp;
				curHP -= tmp * room[i].a;
				if (curHP <= 0) {
					flag = true;
					break;
				}
			}
			else {
				curATK += room[i].a;
				if (curHP + room[i].h <= m) curHP += room[i].h;
				else curHP = m;
			}
		}
		if (flag) l = m + 1;
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

	cin >> n >> atk;
	for (int i = 0; i < n; ++i) {
		cin >> room[i].t >> room[i].a >> room[i].h;
	}
	cout << binary_search(1, 150000000000000000);

	return 0;
}
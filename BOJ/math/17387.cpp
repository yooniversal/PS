//17387

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
typedef pair<ll, ll> xy;

ll CCW(xy a, xy b, xy c) {
	ll tmp = a.first * b.second + b.first * c.second + c.first * a.second;
	tmp -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

ll process(xy a, xy b, xy c, xy d) {
	ll t1 = CCW(a, b, c) * CCW(a, b, d);
	ll t2 = CCW(c, d, a) * CCW(c, d, b);
	//일직선
	if (t1 == 0 && t2 == 0) {
		if (a > b)	swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && c <= b) return 1;
		else return 0;
	}
	//교차
	if (t1 <= 0 && t2 <= 0) return 1;
	else return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	xy a, b, c, d;

	//input
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	cout << process(a, b, c, d);

	return 0;
}
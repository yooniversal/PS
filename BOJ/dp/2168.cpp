//2168

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

ll GCD(ll w, ll h) {
	while (h != 0) {
		ll tmp = w % h;
		w = h;
		h = tmp;
	}
	return w;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll w, h;
	cin >> w >> h;

	if (w > h) {
		ll tmp = w;
		w = h;
		h = tmp;
	}

	ll nw = w / GCD(h, w);
	ll nh = h / GCD(h, w);
	cout << (nh + nw - 1) * GCD(h, w);

	return 0;
}
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
#define INF 987654321
#define MAX 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
		ll ret = 0;
		if (a - n >= x && b - n >= y) ret = min(a - n, b - n) * max(a, b);
		else if (a - n < x && b - n >= y) {
			if (x < b - n) {
				ret = x * (b - (n - (a - x)));
			}
			else {
				ret = a * (b - n);
			}
		}
		else if (a - n >= x && b - n < y) {
			if (y < a - n) {
				ret = y * (a - (n - (b - y)));
			}
			else {
				ret = b * (a - n);
			}
		}
		else {
			if ((a - x) + (b - y) < n) {
				ret = x * y;
			}
			else {
				if (x <= y) {
					ret = x * (b - (n - (a - x)));
				}
				else {
					ret = y * (a - (n - (b - y)));
				}
			}
		}
		cout << ret << '\n';
	}

	return 0;
}
//Codeforces Round #653
//A. Required Number

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
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, x, y, n;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> x >> y >> n;
		
		if (n % x == y) ans = n;
		else if (n % x < y) {
			ans = n - ((n % x) + (x - y));
		}
		else {
			ans = n - ((n%x)-y);
		}

		cout << ans << '\n';
	}

	return 0;
}
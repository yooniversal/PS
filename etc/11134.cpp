//11134

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, c, n;
	cin >> t;

	while (t--) {
		int ans = 0;
		cin >> c >> n;
		ans += c / n;
		c %= n;
		if (c != 0) ans++;
		cout << ans << '\n';
	}

	return 0;
}
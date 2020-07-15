//Codeforces Round #653
//B. Multiply by 2, divide by 6

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

	int t, n;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		if (n == 1) {
			ans = 0;
			cout << ans << '\n';
			continue;
		}
		if (n % 3 != 0) {
			ans = -1;
			cout << ans << '\n';
			continue;
		}
		while (n != 1) {
			if (n % 3 != 0) {
				cout << -1 << '\n';
				break;
			}
			if (n % 6 == 0) n /= 6;
			else n *= 2;
			ans++;
		}
		if(n == 1) cout << ans << '\n';
	}

	return 0;
}
//1871

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		ll ans = 0;

		ans += (s[0] - 'A') * 26 * 26;
		ans += (s[1] - 'A') * 26;
		ans += s[2] - 'A';

		ll tmp = 0;
		for (int i = 4; i <= 7; i++) {
			tmp = tmp * 10 + (s[i] - '0');
		}

		if (abs(ans - tmp) <= 100) cout << "nice" << '\n';
		else cout << "not nice" << '\n';
	}

	return 0;
}
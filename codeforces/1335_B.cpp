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

	int t; cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		string ans, s; char c = 'a';
		for (int i = 0; i < b; i++) {
			s += c;
			c++;
		}
		c = 'a';
		while (ans.size() != n) {
			ans += s;
			if (ans.size() > n)
				ans.erase(ans.begin() + n, ans.end());
		}

		cout << ans << '\n';
	}

	return 0;
}
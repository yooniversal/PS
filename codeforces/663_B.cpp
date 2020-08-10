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
		int n, m; cin >> n >> m;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (s[m - 1] == 'R') ans++;
			if (i == n - 1) {
				for (int j = 0; j < m; j++)
					if (s[j] == 'D') ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
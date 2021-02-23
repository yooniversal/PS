#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int x, y; cin >> y >> x;
		string s; cin >> s;
		int u = 0, d = 0, l = 0, r = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'U') ++u;
			else if (s[i] == 'D') ++d;
			else if (s[i] == 'L') ++l;
			else ++r;
		}

		bool flag = true;
		if (x > 0 && u < x) flag = false;
		else if (x < 0 && d < -x) flag = false;

		if (flag) {
			if (y > 0 && r < y) flag = false;
			else if (y < 0 && l < -y) flag = false;
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
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

	string s; cin >> s;
	string ans, tmp;
	bool a[2] = { false, false };
	for (int i = 0; i < s.size(); i++) {
		tmp += s[i];
		if (s[i] == 'W') a[0] = true;
		else if (s[i] == 'U' && a[0]) a[1] = true;
		else if (s[i] == 'B' && a[0] && a[1]) {
			for (int i = 0; i < tmp.size() - 3; i++) ans += tmp[i];
			if(tmp.size() != 3) ans += " ";
			//ans += ' ';
			tmp = "";
			a[0] = false; a[1] = false;
		}
		else {
			a[0] = false; a[1] = false;
		}

		if (i == s.size() - 1) {
			ans += tmp;
		}
	}

	cout << ans;

	return 0;
}
//6359

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

	int t;
	bool chk[101] = { false, };

	cin >> t;
	while (t--) {
		int num, cnt=1, ans=0;
		cin >> num;

		while (cnt != num + 1) {
			for (int i = cnt; i <= num; i += cnt) {
				if (chk[i]) chk[i] = false;
				else chk[i] = true;
			}

			cnt++;
		}

		for (int i = 1; i <= num; i++)
			if (chk[i]) ans++;

		cout << ans << '\n';
		memset(chk, false, sizeof(chk));
	}

	return 0;
}
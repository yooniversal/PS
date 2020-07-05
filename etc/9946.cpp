//9946

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

int alpha1[26], alpha2[26];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	int cnt = 1, k=0;

	while (1) {
		memset(alpha1, 0, sizeof(alpha1));
		memset(alpha2, 0, sizeof(alpha2));

		cin >> s1 >> s2;
		if (s1.compare(s2) == 0) {
			if (s1 == "END")
				break;
		}

		if (s1.size() != s2.size()) {
			cout << "Case " << cnt << ": different" << '\n';
			cnt++;
			continue;
		}

		for (int i = 0; i < s1.size(); i++) {
			alpha1[s1[i] - 'a']++;
			alpha2[s2[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (alpha1[i] != alpha2[i]) {
				cout << "Case " << cnt << ": different" << '\n';
				cnt++;
				k = 1;
				break;
			}
		}

		if (k != 1) {
			cout << "Case " << cnt << ": same" << '\n';
			cnt++;
		}

		k = 0;
	}

	return 0;
}
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
#define INF 987654321
#define MAX 100001
typedef long long ll;

int chk[26];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		bool ret = true;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < s.size(); j++)
				chk[s[j] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (!chk[i]) continue;
			if (chk[i] % n != 0) {
				ret = false;
				break;
			}
		}

		if (ret) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
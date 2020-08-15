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
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int ans = 0; int one;
		bool turn = true;
		while (s.size() != 0) {
			one = 0;
			vector<pair<int, int>> len;
			bool go = false;
			int start;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '1') {
					if (!go) {
						start = i;
						go = true;
					}
					if (i == s.size() - 1) {
						len.push_back({ start, i });
					}
					one++;
				}
				else {
					if (go) {
						len.push_back({ start, i - 1 });
						go = false;
					}
				}
			}

			if (!one) {
				cout << "0\n";
				break;
			}

			int length = len[0].second - len[0].first;
			pair<int, int> se = { len[0].first, len[0].second };
			for (int i = 1; i < len.size(); i++) {
				if (length < len[i].second - len[i].first) {
					length = len[i].second - len[i].first;
					se = { len[i].first, len[i].second };
				}
			}

			if (turn) ans += length + 1;

			s.erase(se.first, length + 1);
			if (one - (length + 1) == 0) {
				cout << ans << '\n';
				break;
			}
			if (turn) turn = false;
			else turn = true;
		}
	}

	return 0;
}
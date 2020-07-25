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
int ch = 'b';

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];

		string s1;
		for (int i = 0; i < n; i++) {
			string s2;
			if (i == 0) {
				int tmp = a[i];
				while (tmp--) {
					s1 += 'a';
					s2 += 'a';
				}
			}
			else {
				//cout << "ss:"<<s1.size() << '\n';
				for (int j = 0; j < a[i]; j++) {
					s2 += s1[j];
				}
			}

			if (a[i] == 0) {
				if (!s1.size()) s1 = "a";
				if ('a' <= s1[0] && s1[0] < 'z')
					s2 = s1[0] + 1;
				else
					s2 = 'a';
			}

			if (i != n - 1 && s2.size() < a[i + 1]) {
				for (int k = s2.size(); k < a[i + 1]; k++) {
					s2 += ch;
					if ('a' <= ch && ch < 'z')
						ch++;
					else ch = 'b';

				}
			}
			if (i != n - 1)
				cout << s1 << '\n';
			else
				cout << s1 << '\n' << s2 << '\n';

			s1 = s2;
			//cout << "*" << s1 << '\n';
		}
	}

	return 0;
}
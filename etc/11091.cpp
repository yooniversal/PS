//11091

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

bool alpha[26];
char atemp[26];
int cnt = 0;

bool check() {
	bool ans = true;
	cnt = 0;

	for (int i = 0; i < 26; i++)
		if (alpha[i] == false) {
			if (ans == true) ans = false;
			atemp[cnt] = 'a' + i;
			cnt++;
		}
	return ans;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	string str;
	int t;

	cin >> t;
	cin.ignore();

	while (t--) {
		getline(cin, str);

		for (int i = 0; i < str.size(); i++) {
			if ('a' <= str[i] && str[i] <= 'z')
				alpha[str[i] - 'a'] = true;
			if ('A' <= str[i] && str[i] <= 'Z')
				alpha[str[i] - 'A'] = true;
		}

		if (check()) cout << "pangram" << '\n';
		else {
			cout << "missing ";
			for (int i = 0; i < cnt; i++)
				cout << atemp[i];
			cout << '\n';
		}

		memset(atemp, NULL, sizeof(atemp));
		memset(alpha, false, sizeof(alpha));
	}

	return 0;
}
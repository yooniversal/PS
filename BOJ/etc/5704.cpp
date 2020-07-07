//5704

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

bool check() {
	for (int i = 0; i < 26; i++)
		if (alpha[i] == false)
			return false;

	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	string str;
	
	while (1) {
		getline(cin, str);
		if (str[0] == '*') return 0;

		for (int i = 0; i < str.size(); i++) {
			alpha[str[i] - 'a'] = true;
		}

		if (check()) cout << 'Y' << '\n';
		else cout << 'N' << '\n';

		memset(alpha, false, sizeof(alpha));
	}

	return 0;
}
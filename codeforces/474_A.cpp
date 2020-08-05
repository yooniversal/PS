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

string key;

char change(char m, char k) {
	for (int i = 0; i < key.size(); i++) {
		if (key[i] == k) {
			if (k == 'q') {
				if (m == 'L') return 'w';
				else return 'q';
			}
			else if (k == '/') {
				if (m == 'L') return '/';
				else return '.';
			}
			else {
				if (m == 'L') return key[i + 1];
				else return key[i - 1];
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	key = "qwertyuiopasdfghjkl;zxcvbnm,./";

	char m;
	string s;
	cin >> m >> s;

	for (int i = 0; i < s.size(); i++) {
		s[i] = change(m, s[i]);
	}

	cout << s;

	return 0;
}
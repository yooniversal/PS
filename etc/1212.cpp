//1212

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int digit[3];

void digit3(int tmp) {
	digit[0] = tmp / 4; tmp %= 4;
	digit[1] = tmp / 2; tmp %= 2;
	digit[2] = tmp;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			digit3((int)(str[i] - '0'));
			if (digit[0] == 0) {
				if (digit[1] == 0)
					cout << digit[2];
				else
					cout << digit[1] << digit[2];
			}
			else {
				cout << digit[0] << digit[1] << digit[2];
			}
			memset(digit, 0, sizeof(digit));
		}
		else {
			digit3((int)(str[i] - '0'));
			cout << digit[0] << digit[1] << digit[2];
			memset(digit, 0, sizeof(digit));
		}
	}

	return 0;
}
//1259

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	
	while (1) {
		int key = 0;
		cin >> str;

		if (str.size() == 1 && str[0] == '0') return 0;

		for (int i = 0; i < str.size() / 2; i++) {
			//printf("%c %c\n", str[i], str[str.size() - 1 - i]);
			if (str[i] == str[str.size() - 1 - i]) continue;
			else {
				cout << "no" << '\n';
				key = 1;
				break;
			}
		}

		if(key == 0) cout << "yes" << '\n';
	}

	return 0;
}
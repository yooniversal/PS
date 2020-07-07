//2743

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
		if (i % 10 == 9) {
			if (i != 0)
				cout << "\n";
		}
	}

	return 0;
}
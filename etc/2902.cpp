//10808

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (i == 0)
			cout << str[i];
		if (str[i] == '-')
			cout << str[i + 1];
	}

	return 0;
}
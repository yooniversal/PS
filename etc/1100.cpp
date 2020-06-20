//1100

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
	int ans = 0;

	for (int i = 1; i <= 8; i++) {
		cin >> str;
		
		if (i % 2 == 1) {
			for (int j = 0; j < str.size(); j += 2)
				if (str[j] == 'F')
					ans++;
		}
		else {
			for (int j = 1; j < str.size(); j += 2)
				if (str[j] == 'F')
					ans++;
		}
	}

	cout << ans;

	return 0;
}
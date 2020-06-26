//2711

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

	int t, p;
	string str;

	cin >> t;
	while (t--) {
		cin >> p;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
			if (p-1 != i) cout << str[i];
		cout << '\n';
	}

	return 0;
}
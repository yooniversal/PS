//5789

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		string str;
		deque<char> dq;

		cin >> str;
		for (int i = 0; i < str.size(); i++)
			dq.push_back(str[i]);

		while (dq.size() != 2) {
			dq.pop_front();
			dq.pop_back();
		}

		if (dq[0] == dq[1]) cout << "Do-it" << '\n';
		else cout << "Do-it-Not" << '\n';
	}

	return 0;
}
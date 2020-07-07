//5988

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
		string s;
		cin >> s;

		if ((s[s.size() - 1] - '0') % 2 == 0) cout << "even" << '\n';
		else cout << "odd" << '\n';
	}

	return 0;
}
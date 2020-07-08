//7567

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
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int ans = 10;
	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] == str[i]) ans += 5;
		else ans += 10;
	}

	cout << ans;

	return 0;
}
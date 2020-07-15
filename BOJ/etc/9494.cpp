//9494

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

int getblank(string str, int s) {
	if (str.size() < s) return s;
	for (int i = s; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == NULL) return i;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	while (1) {
		string tmp, rm;
		int col = 0;
		cin >> n;
		getline(cin, rm);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			getline(cin, tmp);
			col = getblank(tmp, col);
		}
		cout << col+1 << '\n';
	}

	return 0;
}
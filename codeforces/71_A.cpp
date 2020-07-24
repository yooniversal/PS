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
#include <map>
using namespace std;

typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		if (str.size() > 10) {
			cout << str[0] << str.size() - 2 << str[str.size() - 1] << '\n';
		}
		else {
			cout << str << '\n';
		}
	}

	return 0;
}
//10822

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
	int point = 0;
	long long tmp=0, ans = 0;

	cin >> str;

	while (1) {
		if (str[point] != ',')
			tmp = tmp * 10 + str[point] - '0';
		else {
			ans += tmp;
			//cout << "tmp:" << tmp << endl;
			tmp = 0;
		}

		point++;

		if (point == str.size()) {
			ans += tmp;
			break;
		}
	}

	cout << ans;

	return 0;
}
//10823

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

	string str;
	int tmp = 0, p=0, ans=0;

	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ',') {
				ans += tmp;
				tmp = 0;
				continue;
			}

			tmp = tmp * 10 + (str[i] - '0');
		}
	}

	cout << ans + tmp;

	return 0;
}
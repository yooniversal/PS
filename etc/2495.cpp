//2495

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

	int t = 3, maximum=0, tmp=0;
	string str, re;
	
	while (t--) {
		cin >> str;
		for (int i = 0; i < 8; i++) {
			if (i == 0) {
				re[0] = str[i];
				tmp = 1;
			}
			else {
				if (str[i] == re[0]) {
					tmp++;
				}
				else {
					re[0] = str[i];
					maximum = max(maximum, tmp);
					tmp = 1;
				}
			}
		}
		maximum = max(maximum, tmp);
		cout << maximum << '\n';
		tmp = maximum = 0;
	}

	return 0;
}
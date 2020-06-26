//5026

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

	int t, num1=0, num2=0, point=-1;
	string str;

	cin >> t;
	while (t--) {
		point = -1;
		num1 = 0;
		num2 = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
			if ('0' <= str[i] && str[i] <= '9') {
				num1 = num1 * 10 + str[i] - '0';
			}
			else {
				point = i;
				break;
			}
		if (point == 0) {
			cout << "skipped" << '\n';
			continue;
		}
		for (int i = point + 1; i < str.size(); i++) {
			if ('0' <= str[i] && str[i] <= '9') {
				num2 = num2 * 10 + str[i] - '0';
			}
			if (i == str.size() - 1) {
				cout << num1 + num2 << '\n';
			}
		}
		
	}

	return 0;
}
//3934

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

	int t, tmp, max = 0;

	cin >> t;
	while (t--) {
		cin >> tmp;
		max = tmp;
		while (tmp != 1) {
			if (tmp % 2 == 0) tmp /= 2;
			else tmp = tmp * 3 + 1;
			max = max < tmp ? tmp : max;
		}
		cout << max << '\n';
		max = 0;
	}

	return 0;
}
//2576

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, sum = 0, min=999;

	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 == 1) {
			sum += n;
			if (min > n)
				min = n;
		}
	}

	if (sum != 0)
		cout << sum << "\n" << min;
	else
		cout << "-1";

	return 0;
}
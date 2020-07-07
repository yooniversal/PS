//2475

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

	int n, ans = 0, tmp;

	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		ans += tmp * tmp;
	}

	cout << ans % 10;
	return 0;
}
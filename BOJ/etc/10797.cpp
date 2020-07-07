//10797

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

	int day, n, cnt = 0;

	cin >> day;

	for (int i = 0; i < 5; i++) {
		cin >> n;
		if (day == n) cnt++;
	}

	cout << cnt;

	return 0;
}
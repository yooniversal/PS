//2506

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

	int n, ox, score = 0, cnt = 1;

	cin >> n;
	while (n--) {
		cin >> ox;
		if (ox == 1) {
			score += cnt;
			cnt++;
		}
		else {
			cnt = 1;
		}
	}

	cout << score;

	return 0;
}
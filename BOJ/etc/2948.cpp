//2948

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, d;
	cin >> d >> m;
	int cnt = 0;
	
	for (int i = 1; i < m; i++) {
		if (i <= 7) {
			if (i == 2) {
				cnt += 28;
				continue;
			}
			if (i % 2) cnt += 31;
			else cnt += 30;
		}
		else {
			if (!(i % 2)) cnt += 31;
			else cnt += 30;
		}
	}
	cnt += d - 1;
	cnt %= 7;

	if (cnt == 0) cout << "Thursday";
	else if (cnt == 1) cout << "Friday";
	else if (cnt == 2) cout << "Saturday";
	else if (cnt == 3) cout << "Sunday";
	else if (cnt == 4) cout << "Monday";
	else if (cnt == 5) cout << "Tuesday";
	else if (cnt == 6) cout << "Wednesday";

	return 0;
}
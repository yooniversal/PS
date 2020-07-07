//1924

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int month, day;
	cin >> month >> day;

	int cnt = 0;
	for (int i = 1; i <= month - 1; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			cnt += 31;
		else if (i == 2)
			cnt += 28;
		else
			cnt += 30;

	cnt += day;

	if (cnt % 7 == 0) cout << "SUN";
	else if (cnt % 7 == 1) cout << "MON";
	else if (cnt % 7 == 2) cout << "TUE";
	else if (cnt % 7 == 3) cout << "WED";
	else if (cnt % 7 == 4) cout << "THU";
	else if (cnt % 7 == 5) cout << "FRI";
	else if (cnt % 7 == 6) cout << "SAT";

	return 0;
}
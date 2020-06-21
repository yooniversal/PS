//2490

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

	int n, cnt1 = 0, cnt0 = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n;
			if (n == 0) cnt0++;
			else cnt1++;
		}
		if (cnt0 == 1 && cnt1 == 3) cout << "A" << "\n";
		else if (cnt0 == 2 && cnt1 == 2) cout << "B" << "\n";
		else if (cnt0 == 3 && cnt1 == 1) cout << "C" << "\n";
		else if (cnt0 == 4 && cnt1 == 0) cout << "D" << "\n";
		else cout << "E" << "\n";

		cnt0 = cnt1 = 0;
	}

	return 0;
}
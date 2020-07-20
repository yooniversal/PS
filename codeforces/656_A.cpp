#include <iostream>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, x, y, z;
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		int max = x, min = x;

		if (max < y) max = y;
		if (min > y) min = y;

		if (max < z) max = z;
		if (min > z) min = z;

		int cnt = 0;
		if (max == x) cnt++;
		if (max == y) cnt++;
		if (max == z) cnt++;

		if (cnt <= 1) {
			cout << "No" << '\n';
		}
		else {
			cout << "YES" << '\n';
			if (cnt == 3) cout << max << " " << max << " " << max << '\n';
			if (cnt == 2) {
				cout << min << " " << min << " " << max << '\n';
			}
		}

	}

	return 0;

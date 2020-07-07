//9325

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

	int t, s, n, items, m, sum = 0;

	cin >> t;
	while (t--) {
		cin >> s >> n;
		sum = s;
		while (n--) {
			cin >> items >> m;
			sum += items * m;
		}

		cout << sum << "\n";
		sum = 0;
	}

	return 0;
}
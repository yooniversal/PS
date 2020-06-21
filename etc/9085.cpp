//9085

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

	int t, n, a, sum=0;

	cin >> t;

	while (t--) {
		cin >> n;
		while (n--) {
			cin >> a;
			sum += a;
		}
		cout << sum << "\n";
		sum = 0;
	}

	return 0;
}
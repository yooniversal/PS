//10569

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

	int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << 2 + b - a << "\n";
	}

	return 0;
}
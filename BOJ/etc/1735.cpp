//1735

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	int temp;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x1, x2, y1, y2, x, y;

	cin >> x1 >> y1 >> x2 >> y2;
	y = y1 * y2;
	x = x1 * y2 + x2 * y1;

	int div = GCD(y, x);

	x /= div;
	y /= div;

	cout << x << " " << y;

	return 0;
}
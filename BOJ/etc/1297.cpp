//1297

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	double d, x, y, r;
	int a, b;

	cin >> d >> x >> y;
	
	r = sqrt(d * d / (x * x + y * y));

	a = x * r; b = y * r;
	cout << a << " " << b;

	return 0;
}
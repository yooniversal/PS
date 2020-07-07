//10179

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	double a;

	cin >> t;
	while (t--) {
		cin >> a;
		a *= 0.8;

		printf("$%.2lf\n", a);
	}

	return 0;
}
//5361

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int t, a, b, c, d, e;
	double sum = 0.0;

	cin >> t;

	while(t--) {
		cin >> a >> b >> c >> d >> e;

		sum += 350.34 * (double)a + 230.90 * (double)b + 190.55 * (double)c + 125.30 * (double)d + 180.90 * (double)e;
		printf("$%.2lf\n", sum);

		sum = 0.0;
	}

	return 0;
}
//10833

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

	int n, a, b, sum = 0;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		sum += b % a;
	}
	cout << sum;

	return 0;
}
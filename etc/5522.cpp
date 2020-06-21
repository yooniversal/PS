//5522

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

	int sum = 0, n, tmp;

	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		sum += tmp;
	}
	cout << sum;

	return 0;
}
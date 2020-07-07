//5554

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		sum += a;
	}

	cout << sum / 60 << '\n' << sum % 60;

	return 0;
}
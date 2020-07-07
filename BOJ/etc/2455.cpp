//2455

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

	int in, out, member = 0, max = 0;

	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		member += in - out;
		if (max < member)
			max = member;
	}

	cout << max;

	return 0;
}
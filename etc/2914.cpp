//2914

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

	int a, b;

	cin >> a >> b;
	b *= a;
	b -= a;
	b++;

	cout << b;

	return 0;
}
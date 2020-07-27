//4504

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (1) {
		int v; cin >> v;

		if (v == 0) break;

		if (v < n) {
			cout << v << " is NOT a multiple of " << n << "." << '\n';
			continue;
		}

		if (v % n == 0) {
			cout << v << " is a multiple of " << n << "." << '\n';
		}
		else {
			cout << v << " is NOT a multiple of " << n << "." << '\n';
		}
	}

	return 0;
}
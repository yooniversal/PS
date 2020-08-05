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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 2; n >= (1<<i)-1; i++) {
			if (n % ((1 << i) - 1) == 0) {
				cout << n / ((1 << i) - 1) << '\n';
				break;
			}

		}
	}

	return 0;
}
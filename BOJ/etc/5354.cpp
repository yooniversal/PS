//5354

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

	int n,t;

	cin >> t;

	while(t--) {
		cin >> n;

		if (n == 1) {
			cout << "#\n\n";
			continue;
		}

		for (int i = 0; i < n; i++) cout << "#";
		cout << '\n';
		for (int j = 0; j < n - 2; j++) {
			for (int i = 0; i < n; i++) {
				if (i == 0 || i == n - 1) cout << "#";
				else cout << "J";
			}
			cout << '\n';
		}
		for (int i = 0; i < n; i++) cout << "#";
		cout << "\n\n";
	}

	return 0;
}
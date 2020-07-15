//2776

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
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, t, tmp;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> dp;

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			dp.push_back(tmp);
		}

		sort(dp.begin(), dp.end());

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			if (binary_search(dp.begin(), dp.end(), tmp)) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
	}

	return 0;
}
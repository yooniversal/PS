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
		int x, n, m;
		cin >> x >> n >> m;
		while (n-- && x>20) x = x / 2 + 10;
		while (m--) {
			if (x <= 0) break;
			x -= 10;
		}
		if (x <= 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
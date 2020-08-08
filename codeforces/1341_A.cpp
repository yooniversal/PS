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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;

		int low, high;
		low = a - b; high = a + b;
		low *= n; high *= n;
		if (high < c-d || c+d < low) {
			cout << "No" << '\n';
		}
		else cout << "Yes" << '\n';
	}

	return 0;
}
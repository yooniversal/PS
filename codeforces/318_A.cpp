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

	ll n, k; cin >> n >> k;

	//odd
	if (n % 2) {
		if (k - 1 <= n / 2) cout << 2 * k - 1;
		else cout << (k - 1 - n / 2) * 2;
	}
	//even
	else {
		if (k <= n / 2) cout << 2 * k - 1;
		else cout << (k - n / 2) * 2;
	}

	return 0;
}
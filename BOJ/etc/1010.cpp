//1010

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

int c[31][31];

int com(int n, int k) {
	if (n == k || k == 0) return c[n][k] = 1;
	if (k == 1) return c[n][k] = n;
	if (k > n / 2) return c[n][k] = com(n, n - k);
	if (c[n][k]) return c[n][k];
	return c[n][k] = com(n - 1, k - 1) + com(n - 1, k);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, k, n;
	cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << com(n, k) << '\n';
	}

	return 0;
}
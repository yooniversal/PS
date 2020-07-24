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

	int n, k;
	cin >> n >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > k) ans += 2;
		else ans++;
	}

	cout << ans;

	return 0;
}
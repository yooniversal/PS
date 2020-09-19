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
#define INF 987654321
#define MAX 100001
typedef long long ll;



int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll x, y, k; cin >> x >> y >> k;
		ll all = k * (y + 1);
		ll ret = (all - 1) / (x - 1);
		if ((all - 1) % (x - 1)) ret++;
		cout << ret + k << '\n';
	}

	return 0;
}
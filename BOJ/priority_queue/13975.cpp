//13975

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
#define INF 987654321

typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll t, n, tmp, sum;
	cin >> t;
	while (t--) {
		while (!q.empty()) q.pop();
		sum = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			q.push(tmp);
		}

		ll minval;
		for (int i = 1; i <= n - 1; i++) {
			minval = q.top();
			q.pop();
			minval += q.top();
			q.pop();

			sum += minval;
			q.push(minval);
		}

		cout << sum << '\n';
	}


	return 0;
}
//1927

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

typedef long long ll;
priority_queue < ll, vector <ll>, greater<ll>> q;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	ll tmp;

	cin >> t;
	while (t--) {
		cin >> tmp;
		if (tmp != 0) {
			q.push(tmp);
		}
		else {
			if (!q.empty()) {
				cout << q.top() << '\n';
				q.pop();
			}
			else {
				cout << "0" << '\n';
			}
		}
	}

	return 0;
}
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

	int n; cin >> n;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	if (v[n - 1] == 1) {
		cout << 0; return 0;
	}

	ll tmp = 0, ret = 98765432123456789, pow = 1;
	bool stop = false;
	for (ll c = 1; c <= 100000; c++) {
		for (ll i = 0; i < n; i++) {
			tmp += abs(v[i] - pow);
			pow *= c;
			if (pow > 1e17) {
				stop = true;
				break;
			}
		}
		if (stop) break;
		ret = min(ret, tmp);
		
		tmp = 0; pow = 1;
	}
	cout << ret;

	return 0;
}
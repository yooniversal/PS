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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> p, m, z;
		for (int i = 0; i < n; i++) {
			ll v; cin >> v;
			if (v > 0) p.push_back(v);
			else if (v < 0) m.push_back(v);
			else if (v == 0) z.push_back(v);
		}
		sort(p.rbegin(), p.rend());
		sort(m.begin(), m.end());

		ll ret = -243000000000000001;
		if (p.size() >= 1 && m.size() >= 4) ret = max(ret, p[0] * m[0] * m[1] * m[2] * m[3]);
		if (p.size() >= 3 && m.size() >= 2) ret = max(ret, p[0] * p[1] * p[2] * m[0] * m[1]);
		if (p.size() >= 5) ret = max(ret, p[0] * p[1] * p[2] * p[3] * p[4]);
		if (z.size() != 0) ret = max(ret, 0LL);

		reverse(p.begin(), p.end());
		reverse(m.begin(), m.end());
		if (m.size() >= 5) ret = max(ret, m[0] * m[1] * m[2] * m[3] * m[4]);
		if (p.size() >= 2 && m.size() >= 3) ret = max(ret, p[0] * p[1] * m[0] * m[1] * m[2]);
		if (p.size() >= 4 && m.size() >= 1) ret = max(ret, p[0] * p[1] * p[2] * p[3] * m[0]);

		cout << ret << '\n';
	}

	return 0;
}
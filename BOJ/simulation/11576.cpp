//11576
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, m; cin >> a >> b >> m;
	stack<int> s;
	for (int i = 0; i < m; ++i) {
		int v; cin >> v;
		s.push(v);
	}

	int tmp = 0;
	for (int i = 0, mul = 1; i < m; ++i) {
		tmp += s.top() * mul;
		s.pop(); mul *= a;
	}

	while (tmp >= b) {
		s.push(tmp % b);
		tmp /= b;
	}
	s.push(tmp);

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';

	return 0;
}
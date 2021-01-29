//2089
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

string solve(int n) {
	string ret = "";
	stack<int> s;
	while (!(n == 0 || n == 1)) {
		if (n < 0) {
			if ((-n) % 2 == 0) {
				s.push(0);
				n = (-n) / 2;
			}
			else {
				s.push(1);
				n = (-n) / 2 + 1;
			}
		}
		else {
			if (n % 2 == 0) {
				s.push(0);
				n = -(n / 2);
			}
			else {
				s.push(1);
				n = -(n / 2);
			}
		}
	}
	s.push(n);

	while (!s.empty()) {
		ret += s.top() + '0';
		s.pop();
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	cout << solve(n) << '\n';

	return 0;
}
//16461
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cal(int cur, int end, int add) {
	int ret = 6;
	int tmp = cur;
	if (tmp == end) ret = min(ret, add);

	for(int i=1; i<=6; ++i) {
		tmp -= 20;
		if (tmp < 144000) tmp = 146000;
		if (tmp == end) ret = min(ret, i + add);
	}
	tmp = cur;
	for(int i=1; i<=6; ++i) {
		tmp += 20;
		if (tmp > 146000) tmp = 144000;
		if (tmp == end) ret = min(ret, i + add);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		char now;
		double c1, c2, T;
		cin >> c1 >> c2 >> now >> T;
		int A = c1 * 1000, B = c2 * 1000, end = T*1000;
		if (now == 'A') {
			cout << min(cal(A, end, 0), cal(B, end, 1)) << '\n';
		}
		else {
			cout << min(cal(B, end, 0), cal(A, end, 1)) << '\n';
		}
	}

	return 0;
}
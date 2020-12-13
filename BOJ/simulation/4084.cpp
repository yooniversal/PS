//4084
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		int ret = 0;
		while(1) {
			if (a == b & b == c && c == d) break;
			int na = abs(a - b), nb = abs(b - c), nc = abs(c - d), nd = abs(d - a);
			++ret;
			if (na == nb && nb == nc && nc == nd) break;
			a = na, b = nb, c = nc, d = nd;
		}
		cout << ret << '\n';
	}

	return 0;
}
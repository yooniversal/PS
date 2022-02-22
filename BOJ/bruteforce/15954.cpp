//15964
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, k;
vi a;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	a.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long double ret = 987654321.0;
	for (int t = k; t <= n; ++t) {
		for (int i = 0; i <= n - t; ++i) {

			long double m = 0.0;
			for (int j = i; j < i + t; ++j) {
				m += a[j];
			}
			m /= t;

			long double tmp = 0.0;
			for (int j = i; j < i + t; ++j) {
				long double v = a[j] - m;
				tmp += v * v;
			}
			//cout << "t:"<<t<<" sum:" << tmp << '\n';
			tmp /= (long double)t;
			//cout << "sqrt.tmp:" << sqrt(tmp) << '\n';
			ret = min(ret, sqrt(tmp));
		}
	}

	cout.precision(11);
	cout << ret << '\n';

	return 0;
}
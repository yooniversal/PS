//7453
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vi a, b, c, d;
	for (int i = 0; i < n; ++i) {
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		a.push_back(n1);
		b.push_back(n2);
		c.push_back(n3);
		d.push_back(n4);
	}

	vi arr1, arr2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			arr1.push_back(a[i] + b[j]);
			arr2.push_back(c[i] + d[j]);
		}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	ll ret = 0;
	for (int i = 0; i < arr1.size(); ++i) {
		ll tmp = -arr1[i];
		auto l = lower_bound(arr2.begin(), arr2.end(), tmp);
		auto r = upper_bound(arr2.begin(), arr2.end(), tmp);
		ret += r - l;
	}
	cout << ret;

	return 0;
}
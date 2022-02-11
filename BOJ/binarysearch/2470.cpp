//2470
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;
vector<ll> a;

int binary_search(ll target) {
	int ret = -1, start = 0, end = n - 1;
	int mid = (start + end) / 2;
	ll diff = 2000000000LL;

	while (start < end) {

		mid = (start + end) / 2;
		if (a[mid] != -target && abs(target - a[mid]) < diff) {
			diff = abs(target - a[mid]);
			ret = mid;
		}
		else if (a[mid] == -target) {
			if (mid - 1 >= 0 && mid + 1 <= n - 1) {
				if (abs(a[mid - 1] - target) < abs(a[mid + 1] - target)) return mid - 1;
				return mid + 1;
			}
			else if (mid - 1 >= 0) {
				return mid - 1;
			}
			else {
				return mid + 1;
			}
		}

		if (a[mid] != 0 && a[mid] == target) return mid;
		if (a[mid] > target) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	ll sum = 2000000000LL;
	ii ret = { -1, -1 };
	for (int i = 0; i < n; ++i) {
		int tmp = binary_search(-a[i]);
		if (abs(a[i] + a[tmp]) < sum) {
			ret = { i, tmp };
			sum = abs(a[i] + a[tmp]);
		}
	}

	if (a[ret.first] < a[ret.second]) {
		cout << a[ret.first] << " " << a[ret.second] << '\n';
	}
	else {
		cout << a[ret.second] << " " << a[ret.first] << '\n';
	}

	return 0;
}
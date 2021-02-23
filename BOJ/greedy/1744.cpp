//1744
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

vi a;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, addsum = 0; cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		addsum += a[i];
	}
	sort(a.begin(), a.end());

	int prev = INF, last = -1, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			if (prev != INF) last = i - 1;
			else last = i;
			break;
		}
		if (prev == INF) prev = a[i];
		else {
			sum += prev * a[i];
			prev = INF;
		}
	}
	if(last == -1 && prev != INF) sum += prev;
	prev = INF;

	if (last != -1) {
		bool flag = false;
		for (int i = n - 1; i >= last; --i) {
			if (flag) {
				sum += a[i];
				continue;
			}
			if (a[i] <= 1) {
				sum += a[i];
				if(prev != INF) sum += prev;
				flag = true;
				continue;
			}

			if (prev == INF) prev = a[i];
			else {
				sum += prev * a[i];
				prev = INF;
			}
		}
		if (!flag && prev != INF) sum += prev;
	}

	cout << max(addsum, sum) << '\n';

	return 0;
}
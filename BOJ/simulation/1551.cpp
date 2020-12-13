//1551
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

int a[21], ret[21];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; string s; cin >> n >> k >> s;
	int tmp = 0, cnt = 0;
	bool flag = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ',') {
			if (flag) tmp *= -1, flag = false;
			a[cnt++] = tmp, tmp = 0;
		}
		else {
			if ('0' <= s[i] && s[i] <= '9') tmp = tmp * 10 + s[i] - '0';
			else flag = true;
		}
	}
	if (flag) tmp *= -1;
	a[cnt] = tmp;

	for (int i = 0; i < n; ++i) ret[i] = a[i];

	for (int i = 0, len = n; i < k; ++i, --len) {
		for (int j = 0; j < len - 1; ++j)
			ret[j] = a[j + 1] - a[j];
		for (int j = 0; j < len - 1; ++j)
			a[j] = ret[j];
	}

	for (int i = 0; i < n - k; ++i) {
		cout << ret[i];
		if (i != n - k - 1) cout << ',';
	}
	cout << '\n';

	return 0;
}
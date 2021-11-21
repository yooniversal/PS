//23320
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, y, cnt = 0;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> x >> y;

	for (int i = 0; i < n; ++i) {
		if (a[i] >= y) ++cnt;
	}

	cout << n * x * 0.01 << ' ' << cnt << '\n';
	

	return 0;
}
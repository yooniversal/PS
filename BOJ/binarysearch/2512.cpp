//2512
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi a;
ll M;

ll binary_search() {
	ll l = 1, r = 1000000001;
	while (l+1 < r) {
		ll sum = 0, m = (l + r) / 2;
		for (int i = 0; i < a.size(); ++i)
			if (a[i] <= m) sum += a[i];
			else sum += m;
		if (sum <= M) l = m;
		else r = m;
	}
	return l;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	a.resize(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	cin >> M;

	if (sum > M) cout << binary_search();
	else cout << a.back();

	return 0;
}
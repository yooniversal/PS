#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

ll sum[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	string s; cin >> s;
	sum[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); ++i) {
		sum[i] = sum[i - 1] + s[i] - 'a' + 1;
	}

	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		ll ret = sum[r];
		if (l > 0) ret -= sum[l - 1];
		cout << ret << '\n';
	}

	return 0;
}
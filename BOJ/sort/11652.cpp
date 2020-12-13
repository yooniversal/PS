//11652
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1234567;

bool p[1001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<ll> a, b;
	for (int i = 0; i < n; ++i) {
		ll x; cin >> x;
		a.push_back(x);
	}
	b = a;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	map<ll, int> cnt;
	for (int i = 0; i < n; ++i) ++cnt[b[i]];
	
	ll ret = 0, rcnt = 0;
	for (auto& cur : a) {
		if (rcnt < cnt[cur]) {
			rcnt = cnt[cur];
			ret = cur;
		}
	}
	cout << ret << '\n';
	
	return 0;
}
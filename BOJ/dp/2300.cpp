//2300
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const ll MAX = 100001, INF = 1000000000001, MOD = 1000000007;

int n;
vii tmp;
ll cache[10001];

int cal(int i, int j) {
	int ret = abs(tmp[j].second) * 2;
	ret = max(ret, tmp[j].first - tmp[i].first);
	return ret;
}

ll f(int cur) {
	if (cur == n) return 0;
	ll& ret = cache[cur];
	if (ret != -1) return ret;
	ret = INF;
	int add = 0;
	for (int i = cur; i < n; ++i) {
		add = max(add, cal(cur, i));
		ret = min(ret, f(i + 1) + add);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	tmp.resize(n);
	for (int i = 0; i < n; ++i) cin >> tmp[i].first >> tmp[i].second;
	sort(tmp.begin(), tmp.end());

	cout << f(0) << '\n';

	return 0;
}
//2550
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int mat[10001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vi a, target;
	int n; cin >> n;
	a.resize(n);
	vi sw(n), bulb(n+1);
	for (int i = 0; i < n; ++i) cin >> sw[i];
	for (int i = 1; i <= n; ++i) {
		cin >> bulb[i];
		mat[bulb[i]] = i;
	}
	for (int i = 0; i < n; ++i)
		a[i] = mat[sw[i]];

	stack<ii> tmp; //ÀÎµ¦½º, °ª
	int cnt = 0;
	target.push_back(-INF);
	for (int i = 0; i < n; ++i) {
		if (target[cnt] < a[i]) {
			tmp.push({ ++cnt, a[i] });
			target.push_back(a[i]);
		}
		else {
			auto it = lower_bound(target.begin(), target.end(), a[i]);
			int idx = it - target.begin();
			tmp.push({ idx, a[i] });
			*it = a[i];
		}
	}

	cout << target.size()-1 << '\n';
	vi order;
	while (cnt) {
		if (tmp.top().first == cnt) {
			order.push_back(tmp.top().second);
			--cnt;
		}
		tmp.pop();
	}
	reverse(order.begin(), order.end());
	
	vi ret;
	for (int i = 0; i < order.size(); ++i) ret.push_back(bulb[order[i]]);
	sort(ret.begin(), ret.end());
	for (auto& r : ret) cout << r << ' ';

	return 0;
}

//18407
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

class lazySeg {
private:
	vector<ll> tree, lazy;

	void lazy_update(int node, int ns, int ne) {
		if (lazy[node] == 0) return;
		tree[node] = max(tree[node], lazy[node]);
		if (ns < ne) {
			lazy[node * 2] = max(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = 0;
	}

	void update_range(int node, int ns, int ne, int l, int r, ll val) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return;
		if (l <= ns && ne <= r) {
			lazy[node] = max(lazy[node], val);
			lazy_update(node, ns, ne);
			return;
		}
		int m = (ns + ne) / 2;
		update_range(node * 2, ns, m, l, r, val);
		update_range(node * 2 + 1, m + 1, ne, l, r, val);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}

	ll _find(int node, int ns, int ne, int l, int r) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return -INF;
		if (l <= ns && ne <= r) return tree[node];
		int m = (ns + ne) / 2;
		ll L = _find(node * 2, ns, m, l, r), R = _find(node * 2 + 1, m + 1, ne, l, r);
		return max(L, R);
	}

public:
	lazySeg() {
		tree.resize(MAX * 4, 0);
		lazy.resize(MAX * 4, 0);
	}
	void update(int l, int r, ll val) { update_range(1, 0, MAX - 1, l, r, val); }
	ll find(int l, int r) { return _find(1, 0, MAX - 1, l, r); }
};

vii a;
vi tmp;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, d; cin >> w >> d;
		a.emplace_back(make_pair(d, d + w - 1));
		tmp.emplace_back(d);
		tmp.emplace_back(d + w - 1);
	}
	sort(tmp.begin(), tmp.end());

	int prev = 0, cnt = 0;
	map<int, int> trans;
	for (int i = 0; i < tmp.size(); ++i) {
		if (prev == tmp[i]) trans[tmp[i]] = cnt;
		else trans[tmp[i]] = ++cnt;
		prev = tmp[i];
	}

	for (int i = 0; i < n; ++i) {
		a[i].first = trans[a[i].first];
		a[i].second = trans[a[i].second];
	}

	lazySeg Seg;
	for (int i = 0; i < n; ++i) {
		ll cur = Seg.find(a[i].first, a[i].second);
		Seg.update(a[i].first, a[i].second, cur + 1);
	}

	cout << Seg.find(1, cnt) << '\n';

	return 0;
}
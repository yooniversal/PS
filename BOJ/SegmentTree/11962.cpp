//11962

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 200001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
	vector<ll> tree, lazy, mintree;

	void lazy_update(int node, int ns, int ne) {
		if (lazy[node]) {
			tree[node] += lazy[node] * (ne - ns + 1);
			mintree[node] += lazy[node];
			if (ns != ne) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update_range(int node, int ns, int ne, int l, int r, ll val) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return;
		if (l <= ns && ne <= r) {
			if (ns != ne) {
				lazy[node * 2] += val;
				lazy[node * 2 + 1] += val;
			}
			mintree[node] += val;
			tree[node] += val * (ne - ns + 1);
			return;
		}
		int m = (ns + ne) / 2;
		update_range(node * 2, ns, m, l, r, val);
		update_range(node * 2 + 1, m + 1, ne, l, r, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		mintree[node] = min(mintree[node * 2], mintree[node * 2 + 1]);
	}

	ll _minfind(int node, int ns, int ne, int l, int r) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return INF;
		if (l <= ns && ne <= r) return mintree[node];
		int m = (ns + ne) / 2;
		return min(_minfind(node * 2, ns, m, l, r), _minfind(node * 2 + 1, m + 1, ne, l, r));
	}

	ll _find(int node, int ns, int ne, int l, int r) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return 0;
		if (l <= ns && ne <= r) return tree[node];
		int m = (ns + ne) / 2;
		return _find(node * 2, ns, m, l, r) + _find(node * 2 + 1, m + 1, ne, l, r);
	}

public:
	lazySeg() {
		tree.resize(MAX * 8, 0);
		lazy.resize(MAX * 8, 0);
		mintree.resize(MAX * 8, 0);
	}
	void update(int l, int r, ll val) { update_range(1, 0, MAX - 1, l, r, val); }
	ll find(int l, int r) { return _find(1, 0, MAX - 1, l, r); }
	ll minfind(int l, int r) { return _minfind(1, 0, MAX - 1, l, r); }
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	lazySeg S;
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		S.update(i, i, a);
	}

	while (q--) {
		char c; cin >> c;
		int s, e; cin >> s >> e;
		if (c == 'M') {
			cout << S.minfind(s, e) << '\n';
		}
		else if (c == 'P') {
			ll val; cin >> val;
			S.update(s, e, val);
		}
		else if (c == 'S') {
			cout << S.find(s, e) << '\n';
		}
	}

	return 0;
}
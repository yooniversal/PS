//15967

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
#define MAX 1000002
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
	vector<ll> tree, lazy;

	void lazy_update(int node, int ns, int ne) {
		if (lazy[node]) {
			tree[node] += lazy[node] * (ne - ns + 1);
			if (ns != ne) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	ll update_range(int node, int ns, int ne, int l, int r, ll val) {
		lazy_update(node, ns, ne);
		if (r < ns || ne < l) return tree[node];
		if (l <= ns && ne <= r) {
			if (ns != ne) {
				lazy[node * 2] += val;
				lazy[node * 2 + 1] += val;
			}
			return tree[node] += val * (ne - ns + 1);
		}
		int m = (ns + ne) / 2;
		return tree[node] = update_range(node * 2, ns, m, l, r, val) + update_range(node * 2 + 1, m + 1, ne, l, r, val);
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
	}
	ll update(int l, int r, ll val) { return update_range(1, 0, MAX - 1, l, r, val); }
	ll find(int l, int r) { return _find(1, 0, MAX - 1, l, r); }
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	lazySeg S;
	int n, q1, q2; cin >> n >> q1 >> q2;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		S.update(i, i, a);
	}

	for (int i = 1; i <= q1 + q2; i++) {
		int mode; cin >> mode;
		if (mode == 1) {
			int s, e; cin >> s >> e;
			cout << S.find(s, e) << '\n';
		}
		else if (mode == 2) {
			int s, e, l; cin >> s >> e >> l;
			S.update(s, e, l);
		}
	}

	return 0;
}
//16357
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
		if (lazy[node]) {
			tree[node] += lazy[node];
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
			return tree[node] += val;
		}
		int m = (ns + ne) / 2;
		ll L = update_range(node * 2, ns, m, l, r, val), R = update_range(node * 2 + 1, m + 1, ne, l, r, val);
		return tree[node] = max(L, R);
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
	ll update(int l, int r, ll val) { return update_range(1, 0, MAX-1, l, r, val); }
	ll find(int l, int r) { return _find(1, 0, MAX - 1, l, r); }
};

struct Square {
	int y1, y2;
	Square(int a, int b) : y1(a), y2(b) {}
};

struct Line {
	int y, num, start;
	Line(int c, int d, int e) : y(c), num(d), start(e) {}
	bool operator<(Line& L) {
		if (y != L.y) return y > L.y;
		return start > L.start;
	}
};

int n, END[MAX];
vector<Line> l;
vector<Square> squ;
vi line[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int ux, uy, vx, vy; cin >> ux >> uy >> vx >> vy;
		l.emplace_back(Line(uy, i, 1));
		l.emplace_back(Line(vy, i, 0));
		squ.emplace_back(Square(vy, uy));
	}
	sort(l.begin(), l.end());

	//ÁÂÇ¥ ¾ÐÃà
	int prev = INF, tmp = INF, cnt = 0;
	for (int i = 0; i < l.size(); ++i) {
		tmp = l[i].y;
		if (prev == l[i].y) l[i].y = cnt;
		else l[i].y = ++cnt;

		if (l[i].start) squ[l[i].num].y1 = l[i].y;
		else squ[l[i].num].y2 = l[i].y;
		prev = tmp;
	}
	for (auto& S : squ) {
		line[S.y2].emplace_back(S.y1);
		++END[S.y1 - 1];
	}

	lazySeg Seg;
	for (int i = 0; i < n; ++i) {
		Seg.update(squ[i].y1, squ[i].y2, 1);
	}

	ll ret = Seg.find(1, 2 * n);
	cnt = 0;
	for (int top = 2*n; top >= 1; --top) {
		for (auto& bottom : line[top])
			++cnt, Seg.update(bottom, top, -1);
		cnt -= END[top];
		ret = max(ret, cnt + Seg.find(1, 2*n));
	}

	cout << ret << '\n';

	return 0;
}
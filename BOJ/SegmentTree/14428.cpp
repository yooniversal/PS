//14428
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

class minSeg {
private:
    vector<ll> tree, indextree;
    int size;

    void init(vector<ll>& a, int start, int end, int node) {
        if (start == end) {
            indextree[node] = start;
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        init(a, start, mid, 2 * node);
        init(a, mid + 1, end, 2 * node + 1);
        if (tree[node * 2] < tree[node * 2 + 1]) {
            tree[node] = tree[node * 2];
            indextree[node] = indextree[node * 2];
        }
        else if (tree[node * 2] > tree[node * 2 + 1]) {
            tree[node] = tree[node * 2+1];
            indextree[node] = indextree[node * 2+1];
        }
        else {
            tree[node] = tree[node * 2];
            indextree[node] = min(indextree[node * 2], indextree[node * 2 + 1]);
        }
    }

    void update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return;
        if (start == end) {
            indextree[node] = start;
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, 2 * node, index, value);
        update(mid + 1, end, 2 * node + 1, index, value);
        if (tree[node * 2] < tree[node * 2 + 1]) {
            tree[node] = tree[node * 2];
            indextree[node] = indextree[node * 2];
        }
        else if (tree[node * 2] > tree[node * 2 + 1]) {
            tree[node] = tree[node * 2 + 1];
            indextree[node] = indextree[node * 2 + 1];
        }
        else {
            tree[node] = tree[node * 2];
            indextree[node] = min(indextree[node * 2], indextree[node * 2 + 1]);
        }
    }

    pair<ll, ll> _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return { -1, INF };
        if (left <= start && end <= right) return { indextree[node], tree[node] };
        int mid = (start + end) / 2;
        auto l = _find(start, mid, 2 * node, left, right);
        auto r = _find(mid + 1, end, 2 * node + 1, left, right);
        if (l.second < r.second) return l;
        if (l.second > r.second) return r;
        return l.first <= r.first ? l : r;
    }

public:
    minSeg(vector<ll>& a, int n) {
        size = n;
        tree.resize(100000 * 8, 0);
        indextree.resize(100000 * 8, 0);
        init(a, 0, size - 1, 1);
    }
    void update(int idx, ll val) { update(0, size - 1, 1, idx, val); }
    ll find(int l, int r) { return _find(0, size - 1, 1, l, r).first; }
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    minSeg Seg(a, n);

    int q; cin >> q;
    while (q--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int i, v; cin >> i >> v;
            Seg.update(i-1, v);
        }
        else {
            int i, j; cin >> i >> j;
            cout << Seg.find(i-1, j-1)+1 << '\n';
        }
    }

	return 0;
}

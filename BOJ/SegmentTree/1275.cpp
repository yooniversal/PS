//1275
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class SumSeg {
private:
    vector<ll> tree;
    int size;

    ll init(vector<ll>& a, int start, int end, int node) {
        int mid = (start + end) / 2;
        if (start == end) return tree[node] = a[start];
        return tree[node] = init(a, start, mid, 2 * node) + init(a, mid + 1, end, 2 * node + 1);
    }

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] = value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue + rightValue;
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return _find(start, mid, 2 * node, left, right) + _find(mid + 1, end, 2 * node + 1, left, right);
    }

public:
    SumSeg(vector<ll>& a, int n) {
        size = n;
        tree.resize(MAX * 4, 0);
        init(a, 0, size - 1, 1);
    }
    ll update(int idx, ll val) { return update(0, size - 1, 1, idx, val); }
    ll find(int l, int r) { return _find(0, size - 1, 1, l, r); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SumSeg Seg(a, n);
    while (q--) {
        int x, y, idx, v; cin >> x >> y >> idx >> v;
        --x; --y;
        if (x > y) swap(x, y);
        cout << Seg.find(x, y) << '\n';
        Seg.update(--idx, v);
    }

    return 0;
}
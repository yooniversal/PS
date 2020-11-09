//16978
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class SumSeg {
private:
    vector<ll> tree;

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
    SumSeg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(1, MAX, 1, l, r); }
};

struct M {
    int i, v;
};

struct Q {
    int k, i, j, idx;
    bool operator<(Q& T) {
        return k < T.k;
    }
};

struct RET {
    ll idx, ret;
    bool operator<(RET& R) {
        return idx < R.idx;
    }
};

M modify[MAX];
vector<Q> query;
vector<RET> ret;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    SumSeg Seg;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        Seg.update(i, x);
    }
    int m, k=0, cnt=0; cin >> m;
    while (m--) {
        int mode; cin >> mode;
        if (mode == 1) {
            cin >> modify[++k].i >> modify[k].v;
        }
        else {
            int kth, i, j; cin >> kth >> i >> j;
            query.push_back({ kth,i,j,++cnt });
        }
    }
    sort(query.begin(), query.end());

    int now = 0;
    for (int i = 0; i < query.size(); ++i) {
        while (now < query[i].k) {
            ++now;
            Seg.update(modify[now].i, modify[now].v);
        }
        ret.push_back({ query[i].idx, Seg.find(query[i].i, query[i].j) });
    }

    sort(ret.begin(), ret.end());
    for (auto& r : ret) cout << r.ret << '\n';

    return 0;
}
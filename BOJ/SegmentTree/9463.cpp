//9463
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
    SumSeg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(1, MAX, 1, l, r); }
};

int idx[MAX];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        SumSeg Seg;
        memset(idx, 0, sizeof(idx));
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            idx[x] = i;
        }
        ll ret = 0;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            ret += Seg.find(idx[x], n);
            Seg.update(idx[x], 1);
        }
        cout << ret << '\n';
    }

    return 0;
}
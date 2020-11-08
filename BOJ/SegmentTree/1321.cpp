//1321
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 500001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class kthSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] += value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue + rightValue;
    }

    ll _query(int node, int start, int end, int idx) {
        if (start == end) return start;
        int mid = (start + end) / 2;
        if (idx <= tree[node * 2]) return _query(node * 2, start, mid, idx);
        return _query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
    }

public:
    kthSeg() { tree.resize(MAX * 4, 0); }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll query(int k) { return _query(1, 1, MAX, k); } //k번째 값 호출
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    kthSeg Seg;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        Seg.update(i, x);
    }
    int m; cin >> m;
    while (m--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int i, a; cin >> i >> a;
            Seg.update(i, a);
        }
        else {
            int i; cin >> i;
            cout << Seg.query(i) << '\n';
        }
    }

    return 0;
}
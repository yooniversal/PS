//3653
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
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

int idx[100001]; //idx[i] : i의 실제 인덱스

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int ADD = 100000;
    int t; cin >> t;
    while (t--) {
        SumSeg Seg;
        int n, m, cnt = ADD+1; cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            Seg.update(i + ADD, 1);
            idx[i] = i + ADD;
        }
        while (m--) {
            int x; cin >> x;
            if (idx[x] != 1) cout << Seg.find(1, idx[x] - 1) << ' ';
            else cout << 0 << ' ';
            Seg.update(idx[x], 0);
            Seg.update(--cnt, 1);
            idx[x] = cnt;
        }
        cout << '\n';
    }

    return 0;
}
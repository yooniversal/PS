//17408
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 100001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class maxSeg {
private:
    vector<vector<ll>> tree;

    void update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return;
        if (start == end) {
            tree[node][0] = value;
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, 2 * node, index, value);
        update(mid + 1, end, 2 * node + 1, index, value);
        vector<ll> tmp(4);
        tmp[0] = tree[node * 2][0], tmp[1] = tree[node * 2][1];
        tmp[2] = tree[node * 2 + 1][0], tmp[3] = tree[node * 2 + 1][1];
        sort(tmp.rbegin(), tmp.rend());
        tree[node][0] = tmp[0], tree[node][1] = tmp[1];
    }

    vector<ll> _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return { 0,0 };
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        vector<ll> L = _find(start, mid, 2 * node, left, right), R = _find(mid + 1, end, 2 * node + 1, left, right);
        vector<ll> tmp(4);
        tmp[0] = L[0], tmp[1] = L[1];
        tmp[2] = R[0], tmp[3] = R[1];
        sort(tmp.rbegin(), tmp.rend());
        return { tmp[0], tmp[1] };
    }

public:
    maxSeg() {
        tree.resize(MAX * 4, vector<ll>(2, 0));
    }
    void update(int idx, ll val) { update(1, MAX, 1, idx, val); }
    vector<ll> find(int l, int r) { return _find(1, MAX, 1, l, r); }
};
int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    maxSeg Seg;

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        Seg.update(i, x);
    }
   
    int m; cin >> m;
    while (m--) {
        int q, i, j; cin >> q >> i >> j;
        if (q == 1) {
            Seg.update(i, j);
        }
        else {
            vector<ll> ret = Seg.find(i, j);
            cout << ret[0]+ret[1] << '\n';
        }
    }

	return 0;
}
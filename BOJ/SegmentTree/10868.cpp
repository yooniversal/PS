//10868
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
    vector<ll> tree;
    int size;

    ll init(vector<ll>& a, int start, int end, int node) {
        int mid = (start + end) / 2;
        //리프 노드
        if (start == end) return tree[node] = a[start];
        return tree[node] = min(init(a, start, mid, 2 * node), init(a, mid + 1, end, 2 * node + 1));
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return INF;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return min(_find(start, mid, 2 * node, left, right), _find(mid + 1, end, 2 * node + 1, left, right));
    }

public:
    minSeg(vector<ll>& a, int n) {
        size = n;
        tree.resize(MAX * 4, 0);
        init(a, 0, size - 1, 1);
    }
    ll find(int l, int r) { return _find(0, size - 1, 1, l, r); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    minSeg Seg(a, n);
    while (m--) {
        int i, j; cin >> i >> j;
        --i; --j;
        cout << Seg.find(i, j) << '\n';
    }

    return 0;
}

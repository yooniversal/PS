//12858
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

class lazySeg {
private:
    struct Node {
        ll val, gcd;
        Node() : val(0), gcd(0) {}
    };
    
    int N = 0;
    vector<Node> tree;
    vector<ll> lazy;

    void lazy_update(int node, int ns, int ne) {
        if (lazy[node]) {
            tree[node].val += lazy[node] * (ne - ns + 1);
            if (ns != ne) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            else tree[node].gcd = tree[node].val;
            lazy[node] = 0;
        }
    }

    ll update_range(int node, int ns, int ne, int l, int r, ll val) {
        lazy_update(node, ns, ne);
        if (r < ns || ne < l) return tree[node].val;
        if (l <= ns && ne <= r) {
            if (ns != ne) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
                
            }
            tree[node].val += val * (ne - ns + 1);
            if (ns == ne) tree[node].gcd = tree[node].val;
            return tree[node].val;
        }
        int m = (ns + ne) / 2;
        return tree[node].val = update_range(node * 2, ns, m, l, r, val) + update_range(node * 2 + 1, m + 1, ne, l, r, val);
    }

    ll GCD(ll a, ll b) {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        while (b != 0) {
            ll tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    ll GCD_init(int node, int ns, int ne) {
        lazy_update(node, ns, ne);
        if (ns == ne) return tree[node].gcd = tree[node].val;
        int m = (ns + ne) / 2;
        return tree[node].gcd = GCD(GCD_init(node * 2, ns, m), GCD_init(node * 2 + 1, m + 1, ne));
    }

    ll _find(int node, int ns, int ne, int l, int r) {
        lazy_update(node, ns, ne);
        if (r < ns || ne < l) return 0;
        if (l <= ns && ne <= r) return tree[node].gcd;
        int m = (ns + ne) / 2;
        return GCD(_find(node * 2, ns, m, l, r), _find(node * 2 + 1, m + 1, ne, l, r));
    }

    ll GCD_update(int node, int ns, int ne, int idx) {
        lazy_update(node, ns, ne);
        if (idx < ns || ne < idx) return tree[node].gcd;
        if (ns == ne) return tree[node].gcd = tree[node].val;
        int m = (ns + ne) / 2;
        return tree[node].gcd = GCD(GCD_update(node * 2, ns, m, idx), GCD_update(node * 2 + 1, m + 1, ne, idx));
    }

public:
    lazySeg(int n) {
        N = n;
        tree.resize(N * 4, Node());
        lazy.resize(N * 4, 0);
    }
    ll update(int l, int r, ll val) { return update_range(1, 0, N - 1, l, r, val); }
    ll GCD_update(int idx) { return GCD_update(1, 0, N - 1, idx); }
    ll find(int l, int r) { return _find(1, 0, N - 1, l, r); }
    void init() { GCD_init(1, 0, N - 1); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    lazySeg Seg(n);
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        Seg.update(i, i, val);
    }

    Seg.init(); //GCD Init

    int t; cin >> t;
    while (t--) {
        ll op; int l, r; cin >> op >> l >> r;
        l--; r--;
        if (op == 0) {
            cout << Seg.find(l, r) << '\n';
        }
        else {
            Seg.update(l, r, op);
            Seg.GCD_update(l);
            if (l != r) Seg.GCD_update(r);
        }
    }

    return 0;
}
//12858

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
    struct Node {
        ll val, gcd;
    };

    Node tree[MAX * 4];
    ll lazy[MAX * 4];

    void lazy_update(int node, int ns, int ne) {
        if (lazy[node]) {
            tree[node].val += lazy[node] * (ne - ns + 1);
            if (ns != ne) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
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
            return tree[node].val += val * (ne - ns + 1);
        }
        int m = (ns + ne) / 2;
        return tree[node].val = update_range(node * 2, ns, m, l, r, val) + update_range(node * 2 + 1, m + 1, ne, l, r, val);
    }

    ll GCD(ll a, ll b) {
        if (a < b) swap(a, b);
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
        if (idx < ns || ne < idx) return tree[node].gcd;
        lazy_update(node, ns, ne);
        if (ns == ne) return tree[node].gcd = tree[node].val;
        int m = (ns + ne) / 2;
        return tree[node].gcd = GCD(GCD_update(node * 2, ns, m, idx), GCD_update(node * 2 + 1, m + 1, ne, idx));
    }

public:
    lazySeg() {}
    ll update(int l, int r, ll val) { return update_range(1, 0, MAX - 1, l, r, val); }
    ll GCD_update(int idx) { return GCD_update(1, 0, MAX - 1, idx); }
    ll find(int l, int r) { return _find(1, 0, MAX - 1, l, r); }
    void init() { GCD_init(1, 0, MAX - 1); }
};

lazySeg Seg;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        Seg.update(i, i, val);
    }

    Seg.init();

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
            if(l!=r) Seg.GCD_update(r);
        }
    }
    
    return 0;
}
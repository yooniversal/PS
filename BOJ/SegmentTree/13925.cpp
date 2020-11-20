//13925
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
    vector<ll> tree;
    vector<vector<ll>> lazy; //[0]:Аі [1]:Че

    void lazy_update(int node, int ns, int ne) {
        if (lazy[node][0] == 1 && lazy[node][1] == 0) return;
        tree[node] *= lazy[node][0];
        tree[node] %= MOD;
        if (ns != ne) {
            lazy[node * 2][0] *= lazy[node][0];
            lazy[node * 2 + 1][0] *= lazy[node][0];
            lazy[node * 2][0] %= MOD;
            lazy[node * 2 + 1][0] %= MOD;
        }

        tree[node] += lazy[node][1] * (ne - ns + 1);
        tree[node] %= MOD;
        if (ns != ne) {
            lazy[node * 2][1] *= lazy[node][0];
            lazy[node * 2 + 1][1] *= lazy[node][0];
            lazy[node * 2][1] += lazy[node][1];
            lazy[node * 2 + 1][1] += lazy[node][1];
            lazy[node * 2][1] %= MOD;
            lazy[node * 2 + 1][1] %= MOD;
        }
        lazy[node][0] = 1, lazy[node][1] = 0;
    }

    ll update_range(int node, int ns, int ne, int l, int r, ll a, ll b) {
        lazy_update(node, ns, ne);
        if (r < ns || ne < l) return tree[node];
        if (l <= ns && ne <= r) {
            lazy[node][0] *= a;
            lazy[node][1] += b;
            lazy_update(node, ns, ne);
            return tree[node];
        }
        int m = (ns + ne) / 2;
        tree[node] = update_range(node * 2, ns, m, l, r, a, b) % MOD + update_range(node * 2 + 1, m + 1, ne, l, r, a, b) % MOD;
        tree[node] %= MOD;
        return tree[node];
    }

    ll _find(int node, int ns, int ne, int l, int r) {
        lazy_update(node, ns, ne);
        if (r < ns || ne < l) return 0;
        if (l <= ns && ne <= r) return tree[node];
        int m = (ns + ne) / 2;
        return (_find(node * 2, ns, m, l, r) % MOD + _find(node * 2 + 1, m + 1, ne, l, r) % MOD) % MOD;
    }

public:
    lazySeg() {
        tree.resize(MAX * 4, 0);
        lazy.resize(MAX * 4, vector<ll>(2, 0));
        for (int i = 0; i < MAX * 4; ++i) lazy[i][0] = 1;
    }
    ll update(int l, int r, ll a, ll b) { return update_range(1, 1, MAX, l, r, a, b); }
    ll find(int l, int r) { return _find(1, 1, MAX, l, r); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    lazySeg Seg;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        Seg.update(i, i, 1, x);
    }

    int m; cin >> m;
    while (m--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int x, y, v; cin >> x >> y >> v;
            Seg.update(x, y, 1, v);
        }
        else if (mode == 2) {
            int x, y, v; cin >> x >> y >> v;
            Seg.update(x, y, v, 0);
        }
        else if (mode == 3) {
            int x, y, v; cin >> x >> y >> v;
            Seg.update(x, y, 0, v);
        }
        else {
            int x, y; cin >> x >> y;
            cout << Seg.find(x, y) << '\n';
        }
    }

    return 0;
}
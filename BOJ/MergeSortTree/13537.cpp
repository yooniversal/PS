//13544
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi tree[MAX * 4];

void update(int s, int e, int node, int idx, int val) {
    if (idx < s || e < idx) return;
    int m = (s + e) / 2;
    tree[node].push_back(val);
    if (s != e) {
        update(s, m, 2 * node, idx, val);
        update(m + 1, e, 2 * node + 1, idx, val);
    }
}

int query(int s, int e, int node, int l, int r, int val) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
    int m = (s + e) / 2;
    return query(s, m, 2 * node, l, r, val) + query(m + 1, e, 2 * node + 1, l, r, val);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        update(1, MAX, 1, i, v);
    }
    for (int i = 0; i < MAX * 4; ++i)
        sort(tree[i].begin(), tree[i].end());

    int m; cin >> m;
    int last_ans = 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        cout << query(1, MAX, 1, a, b, c) << '\n';
    }

    return 0;
}
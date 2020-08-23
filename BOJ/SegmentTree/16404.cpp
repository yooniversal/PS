//16404

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

ll tree[MAX * 8], lazy[MAX * 8];
int s[MAX], e[MAX];
vi member[MAX];

void lazy_update(int node, int ns, int ne) {
    if (lazy[node]) {
        tree[node] += lazy[node] * (ne - ns + 1);
        if (ns != ne) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int node, int ns, int ne, int l, int r, ll val) {
    lazy_update(node, ns, ne);
    if (r < ns || ne < l) return tree[node];
    if (l <= ns && ne <= r) {
        if (ns != ne) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return tree[node] += val * (ne - ns + 1);
    }
    int m = (ns + ne) / 2;
    return tree[node] = update_range(node * 2, ns, m, l, r, val) + update_range(node * 2 + 1, m + 1, ne, l, r, val);
}

ll sum(int node, int ns, int ne, int idx) {
    lazy_update(node, ns, ne);
    if (idx < ns || ne < idx) return 0;
    if (ns == ne) return tree[node];
    int m = (ns + ne) / 2;
    return sum(node * 2, ns, m, idx) + sum(node * 2 + 1, m + 1, ne, idx);
}

void dfs(int cur, int& num) {
    s[cur] = ++num;
    for (auto& next : member[cur]) {
        dfs(next, num);
    }
    e[cur] = num;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    int superior; cin >> superior;
    for (int i = 2; i <= n; i++) {
        cin >> superior;
        member[superior].push_back(i);
    }
    int num = 0;
    dfs(1, num);

    while (m--) {
        int ver; cin >> ver;
        if (ver == 1) {
            int who; ll a; cin >> who >> a;
            update_range(1, 1, n, s[who], e[who], a);
        }
        else {
            int who; cin >> who;
            cout << sum(1, 1, n, s[who]) << '\n';
        }
    }

    return 0;
}
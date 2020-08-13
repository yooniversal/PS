//15782

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
#define MAXSIZE 500001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll tree[MAXSIZE * 4], lazy[MAXSIZE * 4], first[MAXSIZE];

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = first[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) ^ init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if ((end - start + 1) % 2) tree[node] ^= lazy[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int start, int end, int node, int left, int right, ll diff) {
    update_lazy(node, start, end);

    if (right < start || end < left) return tree[node];
    if (left <= start && end <= right) {
        if ((end - start + 1) % 2) tree[node] ^= diff;
        if (start != end) {
            lazy[node * 2] ^= diff;
            lazy[node * 2 + 1] ^= diff;
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = update_range(start, mid, node * 2, left, right, diff) ^ update_range(mid + 1, end, node * 2 + 1, left, right, diff);
}

ll query(int start, int end, int node, int left, int right) {
    update_lazy(node, start, end);

    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}


int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> first[i];
    }
    init(1, 1, n);

    int m; cin >> m;
    while (m--) {
        int ver; cin >> ver;
        if (ver == 2) {
            int l, r; cin >> l >> r; l++; r++;
            if (l > r) swap(l, r);
            cout << query(1, n, 1, l, r) << '\n';

        }
        else {
            int l, r, x; cin >> l >> r >> x;
            l++; r++;
            if (l > r) swap(l, r);
            update_range(1, n, 1, l, r, x);
        }

    }

    return 0;
}
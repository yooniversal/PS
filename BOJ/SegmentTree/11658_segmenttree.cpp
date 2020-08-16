//11658
//2d segment tree

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
#define MAX 1025
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi tree;
int h = 1;

void update(int x1, int y1, int val) {
    int y = y1 + h - 1, x = x1 + h - 1;
    tree[y][x] = val;
    while (x > 1) {
        x /= 2;
        tree[y][x] = tree[y][x * 2] + tree[y][x * 2 + 1];
    }
    while (y > 1) {
        x = x1 + h - 1;
        y /= 2;
        tree[y][x] = tree[y * 2][x] + tree[y * 2 + 1][x];
        while (x > 1) {
            x /= 2;
            tree[y][x] = tree[y][x * 2] + tree[y][x * 2 + 1];
        }
    }
    return;
}

int xquery(int y, int nodeL, int nodeR, int node, int start, int end) {
    if (nodeR < start || end < nodeL) return 0;
    if (nodeL <= start && end <= nodeR) return tree[y][node];
    int mid = (start + end) / 2;
    return xquery(y, nodeL, nodeR, node * 2, start, mid) + xquery(y, nodeL, nodeR, node * 2 + 1, mid + 1, end);
}

int yquery(int nodeL, int nodeR, int node, int start, int end, int x1, int x2) {
    if (nodeR < start || end < nodeL) return 0;
    if (nodeL <= start && end <= nodeR) return xquery(node, x1, x2, 1, 1, h);
    int mid = (start + end) / 2;
    return yquery(nodeL, nodeR, node * 2, start, mid, x1, x2) + yquery(nodeL, nodeR, node * 2 + 1, mid + 1, end, x1, x2);
}

int query(int y1, int y2, int x1, int x2) {
    return yquery(y1, y2, 1, 1, h, x1, x2);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    while (h < n) h = h << 1;
    tree.resize(h * 2);
    for (int i = 0; i < h * 2; i++) tree[i].resize(h * 2);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int val; cin >> val;
            update(i, j, val);
        }

    while (m--) {
        int q; cin >> q;
        if (q == 0) {
            int x, y, val;
            cin >> x >> y >> val;
            update(x, y, val);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (y1 > y2) swap(y1, y2);
            if (x1 > x2) swap(x1, x2);
            cout << query(y1, y2, x1, x2) << '\n';
        }
    }

    return 0;
}
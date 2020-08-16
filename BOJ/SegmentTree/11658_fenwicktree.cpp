//11658
//2d fenwick tree

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

ll tree[MAX][MAX];
int n, m;

void update(int y, int x, ll diff) {
    for (int i = y; i <= n; i += (i & -i)) {
        for (int j = x; j <= n; j += (j & -j)) {
            tree[i][j] += diff;
        }
    }
}

ll sum(int y, int x) {
    ll ret = 0;
    for (int i = y; i > 0; i -= (i & -i)) {
        for (int j = x; j > 0; j -= (j & -j)) {
            ret += tree[i][j];
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int val; cin >> val;
            update(i, j, val);
        }

    while (m--) {
        int q; cin >> q;
        if (q == 0) {
            int x, y; ll val;
            cin >> x >> y >> val;
            ll origin = sum(x, y) - sum(x - 1, y) - sum(x, y - 1) + sum(x - 1, y - 1);
            update(x, y, val-origin);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (y1 > y2) swap(y1, y2);
            if (x1 > x2) swap(x1, x2);
            ll ans = sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
            cout << ans << '\n';
        }
    }

    return 0;
}
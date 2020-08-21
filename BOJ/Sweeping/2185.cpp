//2185

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 20005
#define ADD 10002LL
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll tree[MAX * 8], cnt[MAX * 8];

//세로
struct h {
    ll x, lowy, highy, start;

    h(ll x, ll lowy, ll highy, ll start) : x(x), lowy(lowy), highy(highy), start(start) {}
    bool operator<(const h& l) const { 
        return x == l.x ? start > l.start : x < l.x;
    }
};

//가로
struct w {
    ll y, lowx, highx, start;

    w(ll y, ll lowx, ll highx, ll start) : y(y), lowx(lowx), highx(highx), start(start) {}
    bool operator<(const w& l) const { 
        return y == l.y ? start > l.start : y < l.y;
    }
};

void update(int node, int ns, int ne, int l, int r, ll val) {
    if (r < ns || ne < l) return;
    if (l <= ns && ne <= r) cnt[node] += val;
    else {
        int m = (ns + ne) / 2;
        update(node * 2, ns, m, l, r, val);
        update(node * 2 + 1, m + 1, ne, l, r, val);
    }
    if (cnt[node]) tree[node] = ne - ns + 1;
    else
        if (ns == ne) tree[node] = 0;
        else tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<h> height;
    vector<w> width;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        height.push_back({ x1 + ADD, y1 + ADD, y2 + ADD - 1, 1 });
        height.push_back({ x2 + ADD, y1 + ADD, y2 + ADD - 1, -1 });
        width.push_back({ y1 + ADD, x1 + ADD, x2 + ADD - 1, 1 });
        width.push_back({ y2 + ADD, x1 + ADD, x2 + ADD - 1, -1 });
    }
    sort(height.begin(), height.end());
    sort(width.begin(), width.end());

    //세로
    h prevh = height[0];
    ll ret = 0, beforeh = 0;
    for (int i = 0; i < 2 * n; i++) {
        h cur = height[i];

        update(1, 0, MAX - 1, cur.lowy, cur.highy, cur.start);
        ll afterh = tree[1];
        ret += abs(afterh - beforeh);

        beforeh = afterh;
        prevh = cur;
    }

    memset(tree, 0, sizeof(tree));
    memset(cnt, 0, sizeof(cnt));

    //가로
    w prevw = width[0];
    ll beforew = 0;
    for (int i = 0; i < 2 * n; i++) {
        w cur = width[i];

        update(1, 0, MAX - 1, cur.lowx, cur.highx, cur.start);
        ll afterw = tree[1];
        ret += abs(afterw - beforew);

        beforew = afterw;
        prevw = cur;
    }

    cout << ret;

    return 0;
}
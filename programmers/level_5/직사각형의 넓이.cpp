#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100005;

struct line {
    ll x, y1, y2, start;

    line(ll x, ll y1, ll y2, ll start) : x(x), y1(y1), y2(y2), start(start) {}
    bool operator<(const line& l) const { return x < l.x; }
};

ll tree[MAX * 8], cnt[MAX * 8];
vector<line> lines;
vector<ll> values;

void update(int node, int ns, int ne, int l, int r, ll val) {
    if (r < ns || ne < l) return;
    if (l <= ns && ne <= r) cnt[node] += val;
    else {
        int mid = (ns + ne) / 2;
        update(node * 2, ns, mid, l, r, val);
        update(node * 2 + 1, mid + 1, ne, l, r, val);
    }
    if (cnt[node]) tree[node] = values[ne] - values[ns - 1];
    else
        if (ns == ne) tree[node] = 0;
        else tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll solution(vector<vector<int>> rectangles) {

    int n = rectangles.size();
    vector<line> lines;

    for (int i = 0; i < n; i++) {
        ll x1 = rectangles[i][0], y1 = rectangles[i][1];
        ll x2 = rectangles[i][2], y2 = rectangles[i][3];
        lines.push_back({ x1, y1, y2, 1 });
        lines.push_back({ x2, y1, y2, -1 });
        values.push_back(y1); values.push_back(y2);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end()); //중복 제거

    sort(lines.begin(), lines.end()); //x좌표 오름차순으로 정렬

    ll ret = 0;
    line prev = lines[0];
    for (int i = 0; i < 2 * n; i++) {
        line cur = lines[i];
        int dx = cur.x - prev.x;
        ret += dx * tree[1];

        int l = lower_bound(values.begin(), values.end(), cur.y1) - values.begin();
        int r = lower_bound(values.begin(), values.end(), cur.y2) - values.begin();
        update(1, 1, values.size() - 1, ++l, r, cur.start);
        prev = cur;
    }

    return ret;
}
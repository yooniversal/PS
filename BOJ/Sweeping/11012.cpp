//11012

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct line {
    int x, b, t, start;

    line(int x, int b, int t, int start) : x(x), b(b), t(t), start(start) {}
    bool operator<(line& l) { return x == l.x ? start > l.start : x < l.x; }
};

ll tree[MAX * 8], lazy[MAX * 8];
vii folk;
vector<line> lines;
ll ret;

void initialize() {
    ret = 0;
    folk.clear();
    lines.clear();
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
}

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
    return sum(node*2, ns, m, idx) + sum(node*2+1, m + 1, ne, idx);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        initialize();

        //input
        int n, m; cin >> n >> m;
        //folks
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            folk.push_back({ x, y });
        }
        //areas
        for (int i = 0; i < m; i++) {
            int l, r, b, t; cin >> l >> r >> b >> t;
            lines.push_back({ l, b, t, 1 });
            lines.push_back({ r, b, t, -1 });
        }
        sort(folk.begin(), folk.end());
        sort(lines.begin(), lines.end());

        //process
        int id = 0;
        bool end = 0;
        line cur = lines[0];
        for (int i = 0; i < n; i++) {
            if (end) break;
            bool resulted = false, modified = false;
            while (cur.x <= folk[i].first) {
                if (cur.start == -1 && cur.x == folk[i].first && !resulted) {
                    int idx = i;
                    do{
                        ret += sum(1, 0, MAX - 1, folk[idx].second);
                        if (idx < n - 1) {
                            idx++;
                            modified = true;
                        }
                        else break;
                    } while (folk[idx].first == folk[idx-1].first);
                    if(modified) i = --idx;
                    resulted = true;
                }
                update_range(1, 0, MAX - 1, cur.b, cur.t, cur.start);
                if (id < lines.size()-1) cur = lines[++id];
                else {
                    end = true;
                    break;
                }
            }
            if(!resulted) ret += sum(1, 0, MAX - 1, folk[i].second);
        }
        cout << ret << '\n';
    }

    return 0;
}
//17611

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
#define MAX 1000001
#define ADD 500001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
    vector<ll> tree, lazy;
    
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

    ll _find(int node, int ns, int ne, int idx) {
        lazy_update(node, ns, ne);
        if (idx < ns || ne < idx) return 0;
        if (ns == ne) return tree[node];
        int m = (ns + ne) / 2;
        return _find(node * 2, ns, m, idx) + _find(node * 2 + 1, m + 1, ne, idx);
    }

public:
    lazySeg() {
        tree.resize(MAX*8, 0);
        lazy.resize(MAX*8, 0);
    }
    ll update(int l, int r, ll val) { return update_range(1, 0, MAX - 1, l, r, val); }
    ll find(int idx) { return _find(1, 0, MAX - 1, idx); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    lazySeg ROW, COL;
    
    ii xy[2]; //시작점, 끝점
    int X = INF, Y = INF;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x += ADD; y += ADD;
        if (i == 0) {
            X = x, Y = y;
            xy[0].first = x; xy[0].second = y;
        }
        else {
            //가로 업데이트
            if (X != x) {
                int l = min(X, x), r = max(X, x);
                ROW.update(l+1, r, 1);
            }
            else if (Y != y) {
                int l = min(Y, y), r = max(Y, y);
                COL.update(l+1, r, 1);
            }

            if (n - 1) xy[1].first = x, xy[1].second = y;
        }
        X = x; Y = y;
    }

    //시작점과 마지막점은 연결
    if (xy[0].first != xy[1].first) {
        int l = min(xy[0].first, xy[1].first);
        int r = max(xy[0].first, xy[1].first);
        ROW.update(l+1, r, 1);
    }
    else if (xy[0].second != xy[1].second) {
        int l = min(xy[0].second, xy[1].second);
        int r = max(xy[0].second, xy[1].second);
        COL.update(l+1, r, 1);
    }

    ll ret = 0;
    for (int i = 1; i <= MAX; i++)
        ret = max(ret, max(ROW.find(i), COL.find(i)));

    cout << ret;

    return 0;
}
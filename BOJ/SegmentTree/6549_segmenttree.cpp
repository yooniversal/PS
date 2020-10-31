//6549

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
#define MAX 400001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class minSeg {
private:
    vector<ll> tree;
    int size;

    ll init(vector<ll> &a, int start, int end, int node) {
        int mid = (start + end) / 2;
        //리프 노드
        if (start == end) return tree[node] = a[start];
         return tree[node] = min(init(a, start, mid, 2 * node), init(a, mid + 1, end, 2 * node + 1));
    }

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        int mid = (start + end) / 2;
        if (start == end) return tree[node] = value;
        else {
            ll leftValue = update(start, mid, 2 * node, index, value);
            ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
            return tree[node] = min(leftValue, rightValue);
        }
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return INF;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return min(_find(start, mid, 2 * node, left, right), _find(mid + 1, end, 2 * node + 1, left, right));
    }

    ll _query(vector<ll> &a, int start, int end, int node) {
        ll ret = 0;
        if (start == end) return a[start];
        int mid = (start + end) / 2;
        ret = max(_query(a, start, mid, node * 2), _query(a, mid + 1, end, node * 2 + 1));
        int lo = mid, hi = mid + 1;
        ll height = min(a[lo], a[hi]);
        ret = max(ret, height * 2);

        while (start < lo || hi < end) {
            if (hi < end && (lo == start || a[lo - 1] < a[hi + 1])) {
                ++hi;
                height = min(height, a[hi]);
            }
            else {
                --lo;
                height = min(height, a[lo]);
            }
            ret = max(ret, height * (hi - lo + 1) * 1LL);
        }
        return ret;
    }

public:
    minSeg(vector<ll> &a, int n) {
        size = n;
        tree.resize(MAX * 8, 0);
        init(a, 0, size - 1, 1);
    }
    ll update(int idx, ll val) { return update(0, size - 1, 1, idx, val); }
    ll find(int l, int r) { return _find(0, size - 1, 1, l, r); }
    ll query(vector<ll> &a) {
        return _query(a, 0, size - 1, 1);
    }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {
        int n; cin >> n;
        if (n == 0) return 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        minSeg Seg(a, n);
        cout << Seg.query(a) << '\n';
    }

    return 0;
}
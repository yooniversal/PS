//18436
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class SumSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] = value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue + rightValue;
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return _find(start, mid, 2 * node, left, right) + _find(mid + 1, end, 2 * node + 1, left, right);
    }

public:
    SumSeg() {
        tree.resize(MAX * 8, 0);
    }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(1, MAX, 1, l, r); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    SumSeg evenSeg, oddSeg;
    int n; cin >> n;
    vi a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % 2) {
            oddSeg.update(i, 1);
        }
        else {
            evenSeg.update(i, 1);
        }
    }
    int m; cin >> m;
    while (m--) {
        int mode, i, j; cin >> mode >> i >> j;
        if (mode == 1) {
            if (a[i] % 2) {
                if (j % 2 == 0) {
                    oddSeg.update(i, 0);
                    evenSeg.update(i, 1);
                }
            }
            else {
                if (j % 2) {
                    evenSeg.update(i, 0);
                    oddSeg.update(i, 1);
                }
            }
            a[i] = j;
        }
        else if (mode == 2) {
            cout << evenSeg.find(i, j) << '\n';
        }
        else {
            cout << oddSeg.find(i, j) << '\n';
        }
    }

    return 0;
}
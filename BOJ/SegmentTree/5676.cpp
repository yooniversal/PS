//5676
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

class Seg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] = value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue * rightValue;
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 1;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return _find(start, mid, 2 * node, left, right) * _find(mid + 1, end, 2 * node + 1, left, right);
    }

public:
    Seg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(1, MAX, 1, l, r); }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {
        Seg Seg;

        int n, k; cin >> n >> k;
        if (cin.eof() == true) break;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if (x > 0) x = 1;
            else if (x < 0) x = -1;
            else x = 0;
            Seg.update(i, x);
        }
        while (k--) {
            char mode; int i, j;
            cin >> mode >> i >> j;
            if (mode == 'C') {
                if (j > 0) j = 1;
                else if (j < 0) j = -1;
                else j = 0;
                Seg.update(i, j);
            }
            else {
                int ret = Seg.find(i, j);
                if (ret > 0) cout << '+';
                else if (ret < 0) cout << '-';
                else cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}
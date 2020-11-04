//1168
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
    SumSeg() { tree.resize(MAX * 4, 0); }
    ll update(int idx, ll val) { return update(0, MAX - 1, 1, idx, val); }
    ll find(int l, int r) { return _find(0, MAX - 1, 1, l, r); }
};

int n, m;

ll binary_search(SumSeg& Seg, ll l, ll r, ll front) {
    ll ret = 1;
    while (l <= r) {
        ll m = (l + r) / 2, tmp = Seg.find(1, m);
        if (tmp < front) {
            l = m + 1;
        }
        else {
            r = m - 1;
            ret = m;
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    SumSeg Seg;
    for (int i = 1; i <= n; ++i)
        Seg.update(i, 1);
    
    ll front = 1; //현재 위치를 포함한 앞에 있는 갯수
    vector<ll> ret(n, 0);
    int cnt = 0;
    for(int SIZE=n; SIZE>0; --SIZE) {
        front += m - 1;
        front = front % SIZE ? front % SIZE : SIZE;
        ll idx = binary_search(Seg, 1, n, front);
        Seg.update(idx, 0);
        ret[cnt++] = idx;
    }
    
    cout << '<';
    for (int i = 0; i < n; ++i) {
        if (i == 0) cout << ret[i];
        else cout << ", " << ret[i];
    }
    cout << '>';

    return 0;
}
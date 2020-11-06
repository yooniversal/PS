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

    ll _query(int node, int start, int end, int idx) {
        if (start == end) return start;
        int mid = (start + end) / 2;
        if (idx <= tree[node * 2]) return _query(node * 2, start, mid, idx);
        return _query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
    }

public:
    SumSeg() { tree.resize(MAX * 4, 0); }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll query(int k) { return _query(1, 1, MAX, k); } //k번째 값 호출
};

int n, m;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    SumSeg Seg;
    for (int i = 1; i <= n; ++i)
        Seg.update(i, 1);
    
    int cnt = 0;
    vector<ll> ret(n, 0);
    ll front = 1;
    for (int SIZE = n; SIZE > 0; --SIZE) {
        front += m - 1;
        front = front % SIZE ? front % SIZE : SIZE;
        ll idx = Seg.query(front);
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
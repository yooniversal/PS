//2465
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class kthSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] += value;
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
    kthSeg() { tree.resize(MAX * 4, 0); }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll query(int k) { return _query(1, 1, MAX, k); } //k번째 값 호출
};

struct P {
    int n, i;
    bool operator<(P& T) {
        return n < T.n;
    }
    P(int a, int b) : n(a), i(b) {}
    P() { P(0, 0); }
};

int n;
int convert[MAX];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    kthSeg Seg;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].n;
    sort(a.begin(), a.end());
    int cnt = 1;
    a[0].i = cnt;
    Seg.update(cnt, 1);
    convert[1] = a[0].n;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1].n < a[i].n) a[i].i = ++cnt;
        else a[i].i = cnt;
        convert[cnt] = a[i].n;
        Seg.update(cnt, 1);
    }

    vi tmp(n);
    for (int i = n - 1; i >= 0; --i) cin >> tmp[i]; //역순으로 처리해줘야 함

    stack<int> ret;
    for (int i = 0; i < n; ++i) {
        int x = Seg.query(tmp[i] + 1); //앞에 tmp[i]개 만큼 작거나 같은 값을 갖는 인덱스
        Seg.update(x, -1);
        ret.push(convert[x]);
    }

    while (!ret.empty()) {
        cout << ret.top() << '\n';
        ret.pop();
    }

    return 0;
}
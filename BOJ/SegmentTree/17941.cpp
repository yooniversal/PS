//17941
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class maxSeg {
private:
    vi tree;
    int n;

    void init() {
        for (int i = n - 1; i > 0; --i) {
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    int _query(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, tree[l++]);
            if (r & 1) ans = max(ans, tree[--r]);
        }
        return ans;
    }

    void _update(int pos, int val) {
        tree[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
        }
    }

public:
    maxSeg(vi& a, int size) {
        tree.resize(size * 2);
        n = size;
        for (int i = 0; i < n; ++i) tree[n+i] = a[i];
        init();
    }
    int query(int l, int r) { return _query(l, r); }
    void update(int i, int v) { _update(i, v); }
};

int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vvi MAP(n, vi(m));
    vector<maxSeg> H, W; //세로, 가로
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> MAP[i][j];
        maxSeg tmp(MAP[i], m);
        W.push_back(tmp);
    }
    
    for (int i = 0; i < m; ++i) {
        vi arr(n);
        for (int j = 0; j < n; ++j)
            arr[j] = MAP[j][i];
        maxSeg tmp(arr, n);
        H.push_back(tmp);
    }

    int q; cin >> q;
    while (q--) {
        deque<ii> Q;
        int x, y, r, c, k, d; cin >> x >> y >> r >> c >> k >> d;
        --x; --y;
        ll ret = 0;
        
        vi val;
        //세로 최댓값 전처리
        if (d <= 2) {
            val.resize(n);
            for (int i = 0; i < n; ++i)
                val[i] = W[i].query(y, y + c);
        }
        //가로 최댓값 전처리
        else {
            val.resize(m);
            for (int i = 0; i < m; ++i)
                val[i] = H[i].query(x, x + r);
        }

        for (int i = 0; i < k; ++i) {
            if (i == 0) {
                if (d == 1) {
                    int end = x + r;
                    while (x < end) {
                        while (!Q.empty() && val[x] >= Q.back().first) Q.pop_back();
                        Q.push_back({ val[x], x });
                        ++x;
                    }
                    --x;
                }
                else if (d == 2) {
                    int cur = x + r - 1;
                    int end = x - 1;
                    while (cur > end) {
                        while (!Q.empty() && val[cur] >= Q.back().first) Q.pop_back();
                        Q.push_back({ val[cur], cur });
                        --cur;
                    }
                }
                else if (d == 3) {
                    int end = y + c;
                    while (y < end) {
                        while (!Q.empty() && val[y] >= Q.back().first) Q.pop_back();
                        Q.push_back({ val[y], y });
                        ++y;
                    }
                    --y;
                }
                else {
                    int cur = y + c - 1;
                    int end = y - 1;
                    while (cur > end) {
                        while (!Q.empty() && val[cur] >= Q.back().first) Q.pop_back();
                        Q.push_back({ val[cur], cur });
                        --cur;
                    }
                }
            }
            else {
                if (d <= 2) {
                    while (!Q.empty() && abs(Q.front().second - x) >= r) Q.pop_front();
                    while (!Q.empty() && val[x] >= Q.back().first) Q.pop_back();
                    Q.push_back({ val[x], x });
                }
                else {
                    while (!Q.empty() && abs(Q.front().second - y) >= c) Q.pop_front();
                    while (!Q.empty() && val[y] >= Q.back().first) Q.pop_back();
                    Q.push_back({ val[y], y });
                }
            }
            ret ^= Q.front().first;

            if (d == 1) ++x;
            else if (d == 2) --x;
            else if (d == 3) ++y;
            else --y;
        }
        cout << ret << '\n';
    }

    return 0;
}
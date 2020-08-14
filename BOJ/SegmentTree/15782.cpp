//15782

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
#define MAXSIZE 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll tree[MAXSIZE * 4], lazy[MAXSIZE * 4], arr[MAXSIZE];
int s[MAXSIZE], e[MAXSIZE], alter[MAXSIZE];
bool chk[MAXSIZE];
vvi p;

void dfs(int cur, int& num) {
    chk[cur] = true;
    s[cur] = ++num;
    for (auto& next : p[cur])
        if(!chk[next]) dfs(next, num);
    e[cur] = num;
}

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) ^ init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if ((end - start + 1) % 2) tree[node] ^= lazy[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int start, int end, int node, int left, int right, ll diff) {
    update_lazy(node, start, end);

    if (right < start || end < left) return tree[node];
    if (left <= start && end <= right) {
        if ((end - start + 1) % 2) tree[node] ^= diff;
        if (start != end) {
            lazy[node * 2] ^= diff;
            lazy[node * 2 + 1] ^= diff;
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = update_range(start, mid, node * 2, left, right, diff) ^ update_range(mid + 1, end, node * 2 + 1, left, right, diff);
}

ll query(int start, int end, int node, int left, int right) {
    update_lazy(node, start, end);

    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}


int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    p.resize(n + 1);

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    int num = 0;
    dfs(1, num);

    for (int i = 1; i <= n; i++) cin >> arr[s[i]];
    init(1, 1, n);

    while (m--) {
        int ver; cin >> ver;
        if (ver == 1) {
            int who; cin >> who;
            cout << query(1, n, 1, s[who], e[who]) << '\n';
        }
        else {
            int who; ll x; cin >> who >> x;
            update_range(1, n, 1, s[who], e[who], x);
        }
        
    }

    return 0;
}
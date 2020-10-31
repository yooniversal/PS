//2243
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll tree[MAX * 4];

ll update(int node, int start, int end, int idx, ll val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] += val;
    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, idx, val) + update(node * 2 + 1, mid + 1, end, idx, val);
}

ll query(int node, int start, int end, int idx) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (idx <= tree[node * 2]) return query(node * 2, start, mid, idx);
    else return query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    while (n--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int rank; cin >> rank;
            ll idx = query(1, 1, MAX, rank);
            cout << idx << '\n';
            update(1, 1, MAX, idx, -1);
        }
        else {
            int idx, cnt; cin >> idx >> cnt;
            update(1, 1, MAX, idx, cnt);
        }
    }

    return 0;
}

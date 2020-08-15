//12899

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
#define MAX 2000001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll tree[MAX * 4];

ll update(int node, int start, int end, int idx, ll val) {
    if (idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] += val;
    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, idx, val) + update(node * 2 + 1, mid + 1, end, idx, val);
}

ll query(int node, int start, int end, int idx) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (idx <= tree[node * 2]) return query(node * 2, start, mid, idx);
    else return query(node * 2 + 1, mid + 1, end, idx-tree[node * 2]);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    while (n--) {
        int T, X; cin >> T >> X;
        if (T == 1) {
            update(1, 1, MAX, X, 1);
        }
        else {
            ll idx = query(1, 1, MAX, X);
            cout << idx << '\n';
            update(1, 1, MAX, idx, -1);
        }
    }

    return 0;
}
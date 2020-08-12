//16975

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
#define MAXSIZE 1000001
typedef long long ll;

ll tree[MAXSIZE * 4], a[MAXSIZE];

void swap(ll* a, ll* b) { ll tmp = *a; *a = *b; *b = tmp; }

void init(int start, int end, int node) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    tree[node] = 0;
    int mid = (start + end) / 2;
    init(start, mid, 2 * node);
    init(mid + 1, end, 2 * node + 1);
}

void update(int start, int end, int node, int left, int right, ll k) {
    if (right < start || end < left) return;
    if (left <= start && end <= right) {
        tree[node] += k;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, left, right, k);
    update(mid + 1, end, 2 * node + 1, left, right, k);
}

ll sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, 2 * node, left, right) + sum(mid + 1, end, 2 * node + 1, left, right);
}

ll getKey(int start, int end, int node, int index, ll key) {
    if (index < start || end < index) return 0;
    key += tree[node];
    if (start == end) return key;
    int mid = (start + end) / 2;
    return getKey(start, mid, 2 * node, index, key) + getKey(mid+1, end, 2 * node + 1, index, key);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    init(0, N - 1, 1);

    int M; cin >> M;
    while (M--) {
        int Q; cin >> Q;

        //[i, j] update
        if (Q == 1) {
            int i, j, k; cin >> i >> j >> k;
            update(0, N - 1, 1, --i, --j, k);
        }
        //get value at x in tree
        else {
            int index; cin >> index;
            cout << getKey(0, N - 1, 1, --index, 0) << '\n';
        }
    }

    return 0;
}
//1395

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
typedef vector<int> vi;

ll tree[MAXSIZE * 4], lazy[MAXSIZE * 4], arr[MAXSIZE];

ll init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if(lazy[node]%2) tree[node] = abs((end - start + 1) - tree[node]);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int start, int end, int node, int left, int right) {
    update_lazy(node, start, end);

    if (right < start || end < left) return tree[node];
    if (left <= start && end <= right) {
        //lazy[] 업데이트
        if (start != end) {
            lazy[node * 2]++;
            lazy[node * 2 + 1]++;
        }
        return tree[node] = abs((end - start + 1) - tree[node]);
    }
    int mid = (start + end) / 2;
    return tree[node] = update_range(start, mid, node * 2, left, right) + update_range(mid + 1, end, node * 2 + 1, left, right);
}

ll sum(int start, int end, int node, int left, int right) {
    update_lazy(node, start, end);

    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    while (M--) {
        int ver, S, T; cin >> ver >> S >> T;
        S--; T--;
        if (ver == 0) {
            update_range(0, N - 1, 1, S, T);
        }
        else {
            cout << sum(0, N - 1, 1, S, T) << '\n';
        }
    }

    return 0;
}
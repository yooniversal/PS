//10999 

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

ll tree[MAXSIZE*4], lazy[MAXSIZE*4], arr[MAXSIZE];

ll init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int start, int end, int node, int left, int right, ll diff) {
    update_lazy(node, start, end);

    if (right < start || end < left) return tree[node];
    if (left <= start && end <= right) {
        //lazy[] 업데이트
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return tree[node] += (end-start+1)*diff;
    }
    int mid = (start + end) / 2;
    return tree[node] = update_range(start, mid, node*2, left, right, diff) + update_range(mid+1, end, node*2+1, left, right, diff);
}

ll sum(int start, int end, int node, int left, int right) {
    update_lazy(node, start, end);

    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, K; cin >> N >> M >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];
    init(0, N-1, 1);

    M += K;
    while (M--) {
        int ver, s, e; cin >> ver >> s >> e;
        s--; e--;
        //update
        if (ver == 1) {
            ll diff;
            cin >> diff;
            update_range(0, N - 1, 1, s, e, diff);
        }
        //sum
        else {
            cout << sum(0, N - 1, 1, s, e) << '\n';
        }
    }

    return 0;
}
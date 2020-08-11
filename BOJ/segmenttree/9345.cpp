//9345

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

ll maxtree[MAXSIZE*4], mintree[MAXSIZE * 4], a[MAXSIZE];

void swap(ll* a, ll* b) { ll tmp = *a; *a = *b; *b = tmp; }

ll init_max(int start, int end, int node) {
    int mid = (start + end) / 2;
    //리프 노드
    if (start == end) return maxtree[node] = a[start];
    else {
        return maxtree[node] = max(init_max(start, mid, 2 * node), init_max(mid + 1, end, 2 * node + 1));
    }
}

ll init_min(int start, int end, int node) {
    int mid = (start + end) / 2;
    //리프 노드
    if (start == end) return mintree[node] = a[start];
    else {
        return mintree[node] = min(init_min(start, mid, 2 * node), init_min(mid + 1, end, 2 * node + 1));
    }
}

ll maxUpdate(int start, int end, int node, int index, ll value) {
    if (index < start || end < index) return maxtree[node];
    int mid = (start + end) / 2;
    if (start == end) {
        return maxtree[node] = value;
    }
    else {
        return maxtree[node] = max(maxUpdate(start, mid, 2 * node, index, value), maxUpdate(mid + 1, end, 2 * node + 1, index, value));
    }
}

ll minUpdate(int start, int end, int node, int index, ll value) {
    if (index < start || end < index) return mintree[node];
    int mid = (start + end) / 2;
    if (start == end) {
        return mintree[node] = value;
    }
    else {
        ll leftValue = minUpdate(start, mid, 2 * node, index, value);
        ll rightValue = minUpdate(mid + 1, end, 2 * node + 1, index, value);
        return mintree[node] = min(leftValue, rightValue);
    }
}

ll searchMax(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return maxtree[node];
    int mid = (start + end) / 2;
    return max(searchMax(start, mid, 2 * node, left, right), searchMax(mid+1, end, 2*node+1, left, right));
}

ll searchMin(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return INF;
    if (left <= start && end <= right) return mintree[node];
    int mid = (start + end) / 2;
    return min(searchMin(start, mid, 2 * node, left, right), searchMin(mid+1, end, 2*node+1, left, right));
}

void initialize() {
    memset(maxtree, 0, sizeof(maxtree));
    memset(mintree, INF, sizeof(mintree));
    memset(a, 0, sizeof(a));
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        initialize();

        int N, K; cin >> N >> K;
        for (int i = 0; i < N; i++) a[i] = i*1LL;
        init_max(0, N-1, 1);
        init_min(0, N-1, 1);

        while (K--) {
            int Q, A, B; cin >> Q >> A >> B;
            
            //순서 바꾸기
            if (Q == 0) {
                maxUpdate(0, N-1, 1, A, a[B]);
                maxUpdate(0, N-1, 1, B, a[A]);
                minUpdate(0, N - 1, 1, A, a[B]);
                minUpdate(0, N - 1, 1, B, a[A]);
                swap(&a[A], &a[B]);
            }
            //[A, B] 체크
            else {
                if (searchMin(0, N - 1, 1, A, B) == A && searchMax(0, N-1, 1, A, B) == B) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
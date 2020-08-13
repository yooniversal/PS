//14268

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

ll tree[MAXSIZE * 4], lazy[MAXSIZE * 4];
int s[MAXSIZE], e[MAXSIZE];
vvi p;

//cur의 시작(s[cur]) 및 끝(e[cur]) 구간을 정의
void dfs(int cur, int& num) {
    s[cur] = ++num;
    for (auto& next : p[cur])
        dfs(next, num);
    e[cur] = num;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update_range(int start, int end, int node, int left, int right, ll c) {
    update_lazy(node, start, end);

    if (right < start || end < left) return tree[node];
    if (left <= start && end <= right) {
        //lazy[] 업데이트
        if (start != end) {
            lazy[node * 2] += c;
            lazy[node * 2 + 1] += c;
        }
        return tree[node] += (end - start + 1) * c;
    }
    int mid = (start + end) / 2;
    return tree[node] = update_range(start, mid, node * 2, left, right, c) + update_range(mid + 1, end, node * 2 + 1, left, right, c);
}

ll query(int start, int end, int node, int index) {
    update_lazy(node, start, end);

    if (index < start || end < index) return 0;
    if (start == end) return tree[node];

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, index) + query(mid + 1, end, node * 2 + 1, index);
}


int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    p.resize(n + 1);

    int boss;
    cin >> boss; //사장의 상사는 -1

    for (int i = 2; i <= n; i++) {
        cin >> boss;
        p[boss].push_back(i); //i는 boss의 직속 부하
    }
    int num = 0;
    dfs(1, num);

    while (m--) {
        int ver; cin >> ver;
        if (ver == 1) {
            int who; ll c; cin >> who >> c;
            update_range(1, n, 1, s[who], e[who], c);
        }
        else {
            int who; cin >> who;
            cout << query(1, n, 1, s[who]) << '\n';
        }
    }

    return 0;
}
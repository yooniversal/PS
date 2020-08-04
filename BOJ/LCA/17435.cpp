//17435

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
#define MAXSIZE 200001
#define COL 20

typedef long long ll;
int parent[MAXSIZE][COL];
int m;
vector<int> node[MAXSIZE];

void makeTree() {
    //노드 u(1~n)의 부모를 연결하기
    for (int k = 1; k < COL; k++) {
        for (int u = 1; u <= m; u++) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

int query(int cur, int n) {
    for (int i = COL-1; i >= 0; i--) {
        if (parent[cur][i] != -1 && n >= (1<<i)) {
            cur = parent[cur][i];
            n -= (1<<i);
        }
    }

    return cur;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(parent, -1, sizeof(parent));

    //간선
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int p; cin >> p;
        parent[i][0] = p;
    }

    makeTree();

    //쿼리
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int n, x; cin >> n >> x;
        cout << query(x, n) <<'\n';
    }

    return 0;
}
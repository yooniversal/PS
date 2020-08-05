//11437

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
#define COL 20
typedef long long ll;

int parent[MAXSIZE][COL];
int depth[MAXSIZE], n;
vector<int> node[MAXSIZE];
bool chk[MAXSIZE];

//바로 위에 있는 부모와 연결
void dfs(int cur, int d) {
    chk[cur] = true;
    depth[cur] = d; //깊이
    for (int i = 0; i < node[cur].size(); i++) {
        int next = node[cur][i];
        if (chk[next]) continue;
        parent[next][0] = cur; //next의 1(2^0)번째 부모는 cur
        dfs(next, d + 1);
    }
}

void makeTree() {
    dfs(1, 0); //루트가 1

    //노드 u(1~n)의 부모를 연결하기
    for (int k = 1; k < COL; k++) {
        for (int u = 1; u <= n; u++) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

//최소 공통 조상 찾기
int LCA(int a, int b) {
    //깊은쪽을 b로 설정해주고 시작
    if (depth[a] > depth[b]) swap(a, b);

    //깊이가 다른 만큼 맞춰주기
    for (int i = COL - 1; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]]) {
            b = parent[b][i];
        }
    }

    //a와 b가 같다면 -> 최소 공통 조상
    if (a == b) return a;

    //조상이 같아질 때까지 업데이트
    for (int i = COL - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //초기화
    memset(depth, -1, sizeof(depth));

    //input
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        node[c].push_back(p);
        node[p].push_back(c);
    }

    makeTree();

    int m; cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}
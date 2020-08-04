//11438

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
#define MAXSIZE 100001
#define COL 20

typedef long long ll;
int parent[MAXSIZE][COL];
int depth[MAXSIZE], n;
vector<int> node[MAXSIZE];
bool chk[MAXSIZE];

//�ʱ�ȭ
void init() {
    memset(parent, 0, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    memset(chk, false, sizeof(chk));
    for (int i = 1; i <= n; i++)
        node[i].clear();
}

//�ٷ� ���� �ִ� �θ�� ����
void dfs(int cur, int d) {
    chk[cur] = true;
    depth[cur] = d; //����
    for (auto& next : node[cur]) {
        if (chk[next]) continue;
        parent[next][0] = cur; //next�� 1(2^0)��° �θ�� cur
        dfs(next, d + 1);
    }
}

void makeTree() {
    dfs(1, 0); //root�� 1

    //��� u(1~n)�� �θ� �����ϱ�
    for (int k = 1; k < COL; k++) {
        for (int u = 1; u <= n; u++) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

//�ּ� ���� ���� ã��
int LCA(int a, int b) {
    //�������� b�� �������ְ� ����
    if (depth[a] > depth[b]) swap(a, b);

    //���̰� �ٸ� ��ŭ �����ֱ�
    //b�� 2^i��° ������ a�� ���̺��� ũ�ų� ������ ������Ʈ
    for (int i = COL - 1; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]])
            b = parent[b][i];
    }

    //a�� b�� ���ٸ� -> �ּ� ���� ����
    if (a == b) return a;

    //������ ������ ������ ������Ʈ
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

    init();
    cin >> n; //��� ����

    //����
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
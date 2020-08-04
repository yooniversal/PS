//3176

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

struct pv {
    int p, v;
};

typedef long long ll;
int parent[MAXSIZE][COL], MAXV[MAXSIZE][COL], MINV[MAXSIZE][COL];
int depth[MAXSIZE], n;
vector<pv> node[MAXSIZE];
bool chk[MAXSIZE];
int ans_min, ans_max;

//�ٷ� ���� �ִ� �θ�� ����
void dfs(int cur, int d) {
    chk[cur] = true;
    depth[cur] = d; //����
    for (int i = 0; i < node[cur].size(); i++) {
        int next = node[cur][i].p;
        if (chk[next]) continue;
        parent[next][0] = cur; //next�� 1(2^0)��° �θ�� cur
        MAXV[next][0] = node[cur][i].v;
        MINV[next][0] = node[cur][i].v;
        dfs(next, d + 1);
    }
}

void makeTree() {
    dfs(1, 0); //��Ʈ�� 1

    //��� u(1~n)�� �θ� �����ϱ�
    for (int k = 1; k < COL; k++) {
        for (int u = 1; u <= n; u++) {
            MAXV[u][k] = max(MAXV[u][k - 1], MAXV[parent[u][k - 1]][k - 1]);
            MINV[u][k] = min(MINV[u][k - 1], MINV[parent[u][k - 1]][k - 1]);
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }
}

//�ּ� ���� ���� ã��
void LCA(int a, int b) {
    //�������� b�� �������ְ� ����
    if (depth[a] > depth[b]) swap(a, b);

    ans_max = MAXV[b][0]; ans_min = MINV[b][0];

    //���̰� �ٸ� ��ŭ �����ֱ�
    for (int i = COL - 1; i >= 0; i--) {
        if (depth[a] <= depth[parent[b][i]]) {
            ans_max = max(ans_max, MAXV[b][i]);
            ans_min = min(ans_min, MINV[b][i]);
            b = parent[b][i];
        }
    }

    //a�� b�� ���ٸ� -> �ּ� ���� ����
    if (a == b) return;

    //������ ������ ������ ������Ʈ
    for (int i = COL - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            ans_max = max(ans_max, max(MAXV[a][i], MAXV[b][i]));
            ans_min = min(ans_min, min(MINV[a][i], MINV[b][i]));
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ans_max = max(ans_max, max(MAXV[a][0], MAXV[b][0]));
    ans_min = min(ans_min, min(MINV[a][0], MINV[b][0]));
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //�ʱ�ȭ
    memset(depth, -1, sizeof(depth));
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < COL; j++)
            MINV[i][j] = INF;

    //input
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, val;
        cin >> p >> c >> val;
        node[c].push_back({ p, val });
        node[p].push_back({ c, val });
    }

    makeTree();

    int m; cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        LCA(a, b);
        cout << ans_min << " " << ans_max << '\n';
    }

    return 0;
}
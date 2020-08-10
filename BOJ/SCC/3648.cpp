//3648

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
#define MAXSIZE 20001
typedef long long ll;

vector<int> node[MAXSIZE];
vector<vector<int>> SCC;
int chk[MAXSIZE];
bool fin[MAXSIZE];
stack<int> s;
int id, sccnum;

void init() {
    SCC.clear(); id = 0; sccnum = 0;
    while (!s.empty()) s.pop();
    memset(fin, false, sizeof(fin));
    memset(chk, 0, sizeof(chk));
}

int opp(int a) {
    if (a % 2) return a - 1;
    return a + 1;
}

int restore(int a) {
    if (a % 2) return (a + 1) / 2;
    return a / 2 + 1;
}

int dfs(int cur) {
    chk[cur] = ++id;
    s.push(cur);

    int parent = chk[cur];

    for (auto& next : node[cur]) {
        if (chk[next] == 0) parent = min(parent, dfs(next));
        else if (!fin[next]) parent = min(parent, chk[next]);
    }

    //부모일 때 하나의 SCC 생성
    if (chk[cur] == parent) {
        vector<int> subSCC;
        while (1) {
            int node = s.top(); s.pop();
            subSCC.push_back(node);
            fin[node] = true;
            if (chk[node] == parent) break;
        }
        sort(subSCC.begin(), subSCC.end());
        SCC.push_back(subSCC);
        sccnum++;
    }

    return parent;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    //ios_base::sync_with_stdio(false);

    int N, M;
    while (scanf("%d %d", &N, &M) > 0) {
        init();
        while (M--) {
            int a, b;
            scanf("%d %d", &a, &b);
            a = a < 0 ? (-2) * (a + 1) : 2 * a - 1;
            b = b < 0 ? (-2) * (b + 1) : 2 * b - 1;
            node[opp(a)].push_back(b);
            node[opp(b)].push_back(a);
            node[opp(1)].push_back(1);
        }

        //SCC
        for (int i = 1; i <= 2 * N; i++) {
            if (chk[i] == 0) dfs(i);
        }

        int ans = 1;
        for (int i = 0; i < sccnum; i++) {
            for (int j = 0; j < SCC[i].size() - 1; j++) {
                if (restore(SCC[i][j + 1]) == restore(SCC[i][j])) {
                    ans = 0;
                    i = sccnum;
                    break;
                }
            }
        }

        /*for (int i = 0; i < sccnum; i++) {
            cout << "SCC:" << i << " ::";
            for (auto& c : SCC[i]) {
                cout << restore(c) << " ";
            }
            cout << '\n';
        }*/

        if (ans) printf("yes\n");
        else printf("no\n");

        for (int i = 0; i <= 2 * N; i++) node[i].clear();
    }

    return 0;
}
//4196

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

vector<int> node[MAXSIZE];
vector<vector<int>> SCC;
int chk[MAXSIZE], degree[MAXSIZE], uni[MAXSIZE];
bool fin[MAXSIZE];
stack<int> s;
int id, sccnum;

void init() {
    memset(chk, 0, sizeof(chk));
    memset(degree, 0, sizeof(degree));
    memset(fin, false, sizeof(degree));
    memset(uni, 0, sizeof(uni));
    SCC.clear();
    while (!s.empty()) s.pop();
    id = 0; sccnum = 0;
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
        sccnum++;
        while (1) {
            int node = s.top(); s.pop();
            subSCC.push_back(node);
            fin[node] = true;
            uni[node] = sccnum;
            if (chk[node] == parent) break;
        }
        SCC.push_back(subSCC);
    }

    return parent;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        init();

        int V, E; cin >> V >> E;
        while (E--) {
            int a, b; cin >> a >> b;
            node[a].push_back(b); //a->b
        }

        for (int i = 1; i <= V; i++) {
            if (chk[i] == 0) dfs(i);
        }

        //answer
        for (int i = 1; i <= V; i++) {
            for (auto& next : node[i]) {
                //same union
                if (uni[i] == uni[next]) continue;
                degree[uni[next]]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= sccnum; i++)
            if (degree[i] == 0) ans++;

        cout << ans << '\n';

        for (int i = 1; i <= V; i++) node[i].clear();
    }

    return 0;
}
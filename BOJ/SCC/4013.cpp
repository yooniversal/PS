//4013

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
#define MAXSIZE 500001
typedef long long ll;

vector<int> node[MAXSIZE], setEdge[MAXSIZE];
vector<vector<int>> SCC;
int chk[MAXSIZE], degree[MAXSIZE];
int money[MAXSIZE], uni[MAXSIZE];
int SCCcost[MAXSIZE], SCCSavecost[MAXSIZE];
int noderest[MAXSIZE], SCCrest[MAXSIZE];
bool fin[MAXSIZE];
stack<int> s;
int id, sccnum;

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
            uni[node] = sccnum; //어느 집합에 있는지 체크
            SCCcost[sccnum] += money[node]; //각 SCC 현금 합
            if (noderest[node]) SCCrest[sccnum] = true;
            if (chk[node] == parent) break;
        }
        SCC.push_back(subSCC);
    }

    return parent;
}

int ans(int cur) {
    int tmp = 0;
    int& ret = SCCSavecost[cur];
    if (ret != -1) return ret;
    for (auto& next : setEdge[cur]) {
        tmp = max(tmp, ans(next));
    }
    if (tmp == 0) {
        if (!SCCrest[cur]) return ret = 0;
        return ret = SCCcost[cur];
    }
    else {
        return ret = tmp + SCCcost[cur];
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    int V, E; cin >> V >> E;
    while (E--) {
        int a, b; cin >> a >> b;
        node[a].push_back(b); //a->b
    }
    for (int i = 1; i <= V; i++) cin >> money[i]; //각 노드에 있는 돈
    int s, r; cin >> s >> r;
    for (int i = 0; i < r; i++) {
        int isrest; cin >> isrest;
        noderest[isrest] = true;
    }

    //SCC
    for (int i = 1; i <= V; i++) 
        if (chk[i] == 0) dfs(i);

    //노드별 방향에서 집합별 방향으로 변환
    for (int i = 1; i <= V; i++) {
        for (auto& next : node[i]) {
            if (uni[i] == uni[next]) continue; //same union
            setEdge[uni[i]].push_back(uni[next]);
        }
    }

    fill(SCCSavecost, SCCSavecost + sccnum + 1, -1);

    //answer
    cout << ans(uni[s]);

    return 0;
}
//2150

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
#define MAXSIZE 10001
typedef long long ll;

vector<int> node[MAXSIZE];
vector<vector<int>> SCC;
int chk[MAXSIZE];
bool fin[MAXSIZE];
stack<int> s;
int id;

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
    }

    return parent;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int V, E; cin >> V >> E;
    while (E--) {
        int a, b; cin >> a >> b;
        node[a].push_back(b); //a->b
    }

    for (int i = 1; i <= V; i++) {
        if (chk[i] == 0) dfs(i);
    }

    sort(SCC.begin(), SCC.end());

    //answer
    cout << SCC.size() << '\n';
    for (int i = 0; i < SCC.size(); i++) {
        for (int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << " ";
        }
        cout << "-1\n";
    }

    return 0;
}
//16367

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
int id, sccnum, result[MAXSIZE], uni[MAXSIZE];
int k, n;

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
            uni[node] = sccnum;
            if (chk[node] == parent) break;
        }
        sort(subSCC.begin(), subSCC.end());
        SCC.push_back(subSCC);
        sccnum++;
    }

    return parent;
}

void pushToNode(int a, int b) {
    a = a < 0 ? (-2) * (a + 1) : 2 * a - 1;
    b = b < 0 ? (-2) * (b + 1) : 2 * b - 1;
    node[opp(a)].push_back(b);
    node[opp(b)].push_back(a);
}

void solve() {
    for (int i = 0; i < k; i++) {
        if (uni[2 * i] > uni[2 * i + 1]) {
            result[i] = 1;
        }
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k >> n;
    while (n--) {
        int l1, l2, l3; char c1, c2, c3;
        cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;
        if (c1 == 'R') l1 *= -1;
        if (c2 == 'R') l2 *= -1;
        if (c3 == 'R') l3 *= -1;
        pushToNode(l1, l2);
        pushToNode(l1, l3);
        pushToNode(l2, l3);
    }

    //SCC
    for (int i = 0; i < 2 * k; i++) {
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

    if (ans) {
        solve();
        for (int i = 0; i < k; i++)
            if (result[i]) cout << 'B';
            else cout << 'R';
    }
    else cout << "-1";

    return 0;
}
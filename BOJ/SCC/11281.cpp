//11281

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

int N, M;
vector<int> node[MAXSIZE];
vector<vector<int>> SCC;
int chk[MAXSIZE];
bool fin[MAXSIZE];
stack<int> s;
int id, sccnum;
int degree[MAXSIZE], uni[MAXSIZE];
int result[MAXSIZE];
queue<int> q;

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

void solve() {
    for (int i = 0; i < N; i++) {
        if (uni[2*i] > uni[2*i + 1]) result[i] = 1;
        else result[i] = 0;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        a = a < 0 ? (-2) * (a + 1) : 2 * a - 1;
        b = b < 0 ? (-2) * (b + 1) : 2 * b - 1;
        node[opp(a)].push_back(b);
        node[opp(b)].push_back(a);
    }

    //SCC
    for (int i = 0; i < 2 * N; i++) {
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
        cout << ans << '\n';
        solve();

        for (int i = 0; i < N; i++) cout << result[i] << " ";
    }
    else cout << ans;

    return 0;
}
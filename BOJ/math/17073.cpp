#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

vi adj[500005], leaves;
bool chk[500005];

void DFS(int cur) {
    bool isLeaf = true;
    for (auto& next : adj[cur]) {
        if (chk[next]) continue;
        chk[next] = true;
        isLeaf = false;
        DFS(next);
    }

    if (isLeaf) leaves.push_back(cur);
}

int main() {
    FASTIO;

    int n, w; cin >> n >> w;
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    chk[1] = true;
    DFS(1);

    cout << fixed << setprecision(10) << (double)w / leaves.size() << '\n';

    return 0;
}
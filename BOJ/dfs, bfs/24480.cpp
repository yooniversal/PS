#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, m, s;
vector<int> e[100005];
bool chk[100005];
int ret[100005];
int cnt;

void dfs(int cur) {
    ret[cur] = ++cnt;
    
    for(auto& next : e[cur]) {
        if(chk[next]) continue;
        chk[next] = true;
        dfs(next);
    }
}

int main () {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> m >> s;
    while (m--) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i=1; i<=n; ++i)
        sort(e[i].rbegin(), e[i].rend());

    chk[s] = true;
    dfs(s);

    for(int i=1; i<=n; ++i) {
        cout << ret[i] << '\n';
    }

    return 0;
}
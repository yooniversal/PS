#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m;
vector<int> e[100005];
bool fan[100005];
bool chk[100005];
bool ret = false;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void dfs(int cur) {
    if (e[cur].size() == 0) {
        ret = true;
        return;
    }

    for (auto& next : e[cur]) {
        if (ret) break;
        if (chk[next] || fan[next]) continue;
        chk[next] = true;
        dfs(next);
    }
}

int main() {
    FASTIO();

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    int s; cin >> s;
    while (s--) {
        int u; cin >> u;
        fan[u] = true;
    }

    chk[1] = true;
    if (!fan[1]) dfs(1);

    if (ret) cout << "yes" << '\n';
    else cout << "Yes" << '\n';

    return 0;
}
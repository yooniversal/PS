#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int N, M;
vector<int> adj[100005];
int value[100005];
int ans[100005];

void dfs(int cur, int v) {
    ans[cur] += v;

    for (auto& next : adj[cur]) {
        dfs(next, v);
    }
}

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main() {
    FASTIO();

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        int sup; cin >> sup;
        if (sup == -1) continue;
        adj[sup].push_back(i);
    }

    while (M--) {
        int i, w; cin >> i >> w;
        value[i] += w;
    }

    for (int i=1; i<=N; i++) {
        if (value[i] == 0) continue;
        dfs(i, value[i]);
    }

    for (int i=1; i<=N; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
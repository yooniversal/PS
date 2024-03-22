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
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int N, M;
vector<ii> E[5005];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int BFS(int s, int e) {
    bool chk[5005];
    for (int i=0; i<5005; i++) chk[i] = false;

    queue<ii> q;
    q.push({s, 0});
    chk[s] = true;

    while (!q.empty()) {
        int cur = q.front().first, dist = q.front().second; q.pop();
        if (cur == e) return dist;
        
        for (auto& next : E[cur]) {
            if (chk[next.first]) continue;
            chk[next.first] = true;
            q.push({next.first, dist + next.second});
        }
    }

    return -1;
}

int main() {
    FASTIO();

    cin >> N >> M;
    for (int i=0; i<N-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    while (M--) {
        int u, v; cin >> u >> v;
        cout << BFS(u, v) << '\n';
    }

    return 0;
}
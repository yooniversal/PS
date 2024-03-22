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

int N, M, R;
int order[100005];
vector<int> e[100005];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void BFS() {
    queue<int> q;
    q.push(R);
    int cnt = 1;
    order[R] = cnt++;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (auto& next: e[cur]) {
            if (order[next] != 0) continue;
            order[next] = cnt++;
            q.push(next);
        }
    }
}

int main() {
    FASTIO();

    cin >> N >> M >> R;
    while (M--) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i=1; i<=N; i++) {
        sort(e[i].rbegin(), e[i].rend());
    }

    BFS();

    for (int i=1; i<=N; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}
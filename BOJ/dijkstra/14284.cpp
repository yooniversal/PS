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

int N, M, S, T;
int d[5005];
bool chk[5005];
vector<ii> E[5005];

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void init() {
    for (int i=0; i<5005; i++) {
        d[i] = INF;
    }
}

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<ii> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur = pq.top().second, dist = -pq.top().first; pq.pop();

        if (chk[cur]) continue;
        chk[cur] = true;

        if (d[cur] < dist) continue;
        for (auto& next : E[cur]) {
            int next_dist = dist + next.second;
            if (d[next.first] <= next_dist) continue;
            d[next.first] = next_dist;
            pq.push({ -next_dist, next.first });
        }
    }
}

int main() {
    FASTIO();
    init();

    cin >> N >> M;
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    cin >> S >> T;

    dijkstra(S);

    cout << d[T] << '\n';

    return 0;
}
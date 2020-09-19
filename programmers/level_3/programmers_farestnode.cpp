#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 20001;
const int INF = 987654321;

vector<int> node[MAX];
bool chk[MAX];
int dist[MAX];
int MAX_dist;

void bfs(int n) {
    queue<pair<int, int>> q;
    chk[n] = true;
    q.push({ n, 0 });
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        dist[cur.first] = cur.second;
        MAX_dist = max(MAX_dist, cur.second);
        for (auto& next : node[cur.first]) {
            if (chk[next]) continue;
            chk[next] = true;
            q.push({ next, cur.second + 1 });
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    fill(dist + 1, dist + n + 1, INF);

    for (int i = 0; i < edge.size(); ++i) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    bfs(1);

    for (int i = 1; i <= n; ++i)
        if (dist[i] == MAX_dist)
            ++answer;

    return answer;
}
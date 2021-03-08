#include <string>
#include <vector>
using namespace std;

const int INF = 987654321;
int d[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= 200; ++i)
        for (int j = 1; j <= 200; ++j)
            if (i != j)
                d[i][j] = INF;

    for (int i = 0; i < fares.size(); ++i) {
        int u = fares[i][0], v = fares[i][1], w = fares[i][2];
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    int answer = INF;
    for (int i = 1; i <= n; ++i) {
        if (d[s][i] == INF || d[i][a] == INF || d[i][b] == INF) continue;
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }

    return answer;
}
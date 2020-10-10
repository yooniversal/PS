#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;

int d[51][51];

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    for (int i = 0; i < 51; ++i)
        for (int j = 0; j < 51; ++j)
            if (i != j)
                d[i][j] = INF;

    for (int i = 0; i < road.size(); ++i) {
        d[road[i][0]][road[i][1]] = min(d[road[i][0]][road[i][1]], road[i][2]);
        d[road[i][1]][road[i][0]] = min(d[road[i][1]][road[i][0]], road[i][2]);
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    for (int i = 1; i <= N; ++i)
        if (d[1][i] <= K)
            ++answer;

    return answer;
}
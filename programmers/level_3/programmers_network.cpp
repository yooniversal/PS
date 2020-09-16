#include <string>
#include <vector>
#define MAX 201
using namespace std;

bool chk[MAX];
vector<int> node[MAX];

void dfs(int cur) {
    for (auto& next : node[cur]) {
        if (chk[next]) continue;
        chk[next] = true;
        dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++)
        for (int j = 0; j < computers[i].size(); j++)
            if (i != j && computers[i][j])
                node[i].push_back(j);

    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        answer++; dfs(i);
    }

    return answer;
}
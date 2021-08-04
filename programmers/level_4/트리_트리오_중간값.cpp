#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef vector<pair<int, int>> vii;
typedef vector<int> vi;

const int MAX = 250005;
vii a[MAX];
bool chk[MAX];
int long_dist = -1;

vi BFS(int n) {
    vi end_point;
    long_dist = -1;
    memset(chk, false, sizeof(chk));

    queue<pair<int, int>> q;
    chk[n] = true;
    for (auto& next : a[n]) {
        q.push({ next.first, next.second });
    }

    while (!q.empty()) {
        int cur = q.front().first, dist = q.front().second; q.pop();

        if (a[cur].size() <= 1) {
            if (long_dist < dist) {
                long_dist = dist;
                end_point.clear();
                end_point.push_back(cur);
            }
            else if (long_dist == dist) {
                end_point.push_back(cur);
            }

            continue;
        }

        for (auto& next : a[cur]) {
            int nextNum = next.first, nextDist = next.second;
            if (chk[nextNum]) continue;
            chk[nextNum] = true;
            q.push({ nextNum, nextDist + dist });
        }
    }

    return end_point;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;

    for (auto& e : edges) {
        int u = e[0], v = e[1];
        a[u].push_back({ v, 1 });
        a[v].push_back({ u, 1 });
    }

    auto points = BFS(1);
    auto end_points = BFS(points[0]);
    if (end_points.size() > 1) return long_dist;
    end_points = BFS(end_points[0]);
    if (end_points.size() > 1) return long_dist;
    return long_dist - 1;
}
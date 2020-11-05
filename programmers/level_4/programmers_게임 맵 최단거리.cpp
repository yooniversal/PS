#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c;
vector<vector<int>> dist;

bool OOB(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) return true;
    return false;
}

void BFS(const vector<vector<int>>& maps) {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == r - 1 && y == c - 1) break;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (maps[nx][ny] == 0) continue;
            if (dist[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}

int solution(vector<vector<int>> maps) {
    r = maps.size(); c = maps[0].size();
    dist.resize(r, vector<int>(c, 0));
    BFS(maps);
    if (dist[r - 1][c - 1] == 0) return -1;
    return dist[r - 1][c - 1] + 1; //시작 위치 포함
}
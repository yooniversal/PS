#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int INF = 987654321;

struct P {
    int x, y, d, v;
    P(int a, int b, int c, int d) : x(a), y(b), d(c), v(d) {}
};

int d[26][26];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
vector<vector<int>> a;

bool OOB(int x, int y) {
    if (x < 0 || x >= a.size() || y < 0 || y >= a.size()) return true;
    return false;
}

int BFS() {
    queue<P> q;
    q.push(P(0, 0, 1, 0));
    q.push(P(0, 0, 2, 0));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, dir = q.front().d, v = q.front().v;
        q.pop();
        if (x == a.size() - 1 && y == a.size() - 1) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (a[nx][ny] == 1) continue;
            int add = 100;
            if (dir != i) add += 500;
            if (d[nx][ny] >= v + add) {
                d[nx][ny] = v + add;
                q.push(P(nx, ny, i, v + add));
            }
        }
    }
    return d[a.size() - 1][a.size() - 1];
}

int solution(vector<vector<int>> board) {
    a = board;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            d[i][j] = INF;
    return BFS();
}
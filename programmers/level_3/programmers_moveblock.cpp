#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct IN {
    //mode 0:가로 1:세로
    int x, y, cnt, mode;
    IN(int a, int b, int c, int d) : x(a), y(b), cnt(c), mode(d) {}
};

vector<vector<int>> b;
int n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[101][101][2];

bool OOB(int x, int y, int mode) {
    if (mode == 0) {
        if (x < 0 || x >= n || y < 0 || y >= m - 1) return true;
    }
    else {
        if (x < 0 || x >= n - 1 || y < 0 || y >= m) return true;
    }
    return false;
}

int bfs() {
    memset(chk, false, sizeof(chk));
    queue<IN> q;
    q.push({ 0, 0, 0, 0 });
    while (!q.empty()) {
        IN cur = q.front(); q.pop();
        if (OOB(cur.x, cur.y, cur.mode)) continue;
        if (chk[cur.x][cur.y][cur.mode]) continue;
        chk[cur.x][cur.y][cur.mode] = true;
        if ((cur.mode == 0 && cur.x == n - 1 && cur.y == m - 2) || (cur.mode == 1 && cur.x == n - 2 && cur.y == m - 1)) {
            return cur.cnt;
        }

        //mode 유지
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (OOB(nx, ny, cur.mode)) continue;
            if (cur.mode == 0)
                if (b[nx][ny] || b[nx][ny + 1]) continue;
            if (cur.mode == 1)
                if (b[nx][ny] || b[nx + 1][ny]) continue;
            q.push({ nx, ny, cur.cnt + 1, cur.mode });
        }

        //가로 회전
        if (cur.mode == 0) {
            //아래로 회전
            if (cur.x + 1 <= n - 1) {
                if (!b[cur.x + 1][cur.y] && !b[cur.x + 1][cur.y + 1]) {
                    q.push(IN(cur.x, cur.y, cur.cnt + 1, 1));
                    q.push(IN(cur.x, cur.y + 1, cur.cnt + 1, 1));
                }
            }
            //위로 회전
            if (cur.x - 1 >= 0) {
                if (!b[cur.x - 1][cur.y] && !b[cur.x - 1][cur.y + 1]) {
                    q.push(IN(cur.x - 1, cur.y, cur.cnt + 1, 1));
                    q.push(IN(cur.x - 1, cur.y + 1, cur.cnt + 1, 1));
                }
            }
        }
        else {
            //오른쪽 회전
            if (cur.y + 1 <= m - 1) {
                if (!b[cur.x][cur.y + 1] && !b[cur.x + 1][cur.y + 1]) {
                    q.push(IN(cur.x, cur.y, cur.cnt + 1, 0));
                    q.push(IN(cur.x + 1, cur.y, cur.cnt + 1, 0));
                }
            }
            //왼쪽 회전
            if (cur.y - 1 >= 0) {
                if (!b[cur.x][cur.y - 1] && !b[cur.x + 1][cur.y - 1]) {
                    q.push(IN(cur.x, cur.y - 1, cur.cnt + 1, 0));
                    q.push(IN(cur.x + 1, cur.y - 1, cur.cnt + 1, 0));
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size(); m = board[0].size();
    b = board;
    return bfs();
}
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

bool chk[11][11][11][11];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 }; //U, D, R, L

bool OOB(int x, int y) {
    if (x < 0 || x >= 11 || y < 0 || y >= 11) return true;
    return false;
}

int solution(string dirs) {
    int answer = 0;

    int x = 5, y = 5;
    for (int i = 0; i < dirs.size(); ++i) {
        int j = -1;
        if (dirs[i] == 'U') j = 0;
        else if (dirs[i] == 'D') j = 1;
        else if (dirs[i] == 'R') j = 2;
        else j = 3;

        int nx = x + dx[j], ny = y + dy[j];
        if (OOB(nx, ny)) continue;
        if (!chk[x][y][nx][ny]) {
            chk[x][y][nx][ny] = true;
            chk[nx][ny][x][y] = true;
            ++answer;
        }
        x = nx; y = ny;
    }

    return answer;
}
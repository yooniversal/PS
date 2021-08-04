#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> a;
int n;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }
bool highest(int x, int y) {
    --x;
    while (x != -1) {
        if (a[x][y] != 0) return false;
        --x;
    }
    return true;
}

// ¤¤
bool solve1(int x, int y) {
    int kind = a[x][y];
    int dx[3] = { 1,1,1 }, dy[3] = { 0,1,2 };
    bool found = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x + 1, y + 1) && highest(x + 1, y + 2)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = -1, dx[1] = 0, dx[2] = 0, dy[0] = -1, dy[1] = -1, dy[2] = 1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y) && highest(x, y + 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = -1, dx[1] = 0, dx[2] = 0, dy[0] = -2, dy[1] = -2, dy[2] = -1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y) && highest(x, y - 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    return false;
}

// reverse L
bool solve2(int x, int y) {
    int kind = a[x][y];
    int dx[] = { -2,-1,0 }, dy[] = { 1,1,1 };
    bool found = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found) {
        if (highest(x, y)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    }

    found = true;
    dx[0] = 1, dx[1] = 2, dx[2] = 2, dy[0] = 0, dy[1] = -1, dy[2] = 0;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x + 2, y - 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    return false;
}

// reverse ¤¤
bool solve3(int x, int y) {
    int kind = a[x][y];
    int dx[] = { 0,0,-1 }, dy[] = { 1,2,2 };
    bool found = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found) {
        if (highest(x, y) && highest(x, y + 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    }
    found = true;
    dx[0] = 0, dx[1] = -1, dx[2] = 0, dy[0] = -1, dy[1] = 1, dy[2] = 1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y) && highest(x, y - 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = 1, dx[1] = 1, dx[2] = 1, dy[0] = -2, dy[1] = -1, dy[2] = 0;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x + 1, y - 2) && highest(x + 1, y - 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    return false;
}

// reverse L
bool solve4(int x, int y) {
    int kind = a[x][y];
    int dx[] = { 1,2,2 }, dy[] = { 0,0,1 };
    bool found = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x + 2, y + 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = -2, dx[1] = -1, dx[2] = 0, dy[0] = -1, dy[1] = -1, dy[2] = -1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    return false;
}

// ¤Ç
bool solve5(int x, int y) {
    int kind = a[x][y];
    int dx[] = { -1,0,0 }, dy[] = { 1,1,2 };
    bool found = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y) && highest(x, y + 2)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = 1, dx[1] = 1, dx[2] = 1, dy[0] = -1, dy[1] = 0, dy[2] = 1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x + 1, y - 1) && highest(x + 1, y + 1)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }

    found = true;
    dx[0] = 0, dx[1] = -1, dx[2] = 0, dy[0] = -2, dy[1] = -1, dy[2] = -1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) { found = false; break; }
        if (a[nx][ny] != kind) { found = false; break; }
    }
    if (found)
        if (highest(x, y - 2) && highest(x, y)) {
            a[x][y] = 0;
            for (int i = 0; i < 3; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                a[nx][ny] = 0;
            }
            return true;
        }
    return false;
}


int solution(vector<vector<int>> board) {
    n = board.size(); a = board;
    int answer = 0;

    while (1) {
        bool flag = true;
        for (int c = 0; c < n; ++c) {
            int nr = 0;
            while (nr != n) {
                if (a[nr][c] != 0) {
                    int prev = answer;
                    if (solve1(nr, c)) { ++answer; flag = false; }
                    else if (solve2(nr, c)) { ++answer; flag = false; }
                    else if (solve3(nr, c)) { ++answer; flag = false; }
                    else if (solve4(nr, c)) { ++answer; flag = false; }
                    else if (solve5(nr, c)) { ++answer; flag = false; }
                }
                ++nr;
            }
        }
        if (flag) break;
    }

    return answer;
}
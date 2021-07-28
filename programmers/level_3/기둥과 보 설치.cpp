#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool tmap[105][105];
bool bmap[105][105];
int dx[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int N;

bool OOB(int x, int y) {
    if (x<0 || x>N || y<0 || y>N) return true;
    return false;
}

bool canInstall(bool isboard, int x, int y) {
    //±âµÕ
    if (!isboard) {
        //¹Ù´Ú À§
        if (x == N) return true;
        //±âµÕ À§
        if (tmap[x + 1][y]) return true;
        //º¸ ÇÑÂÊ³¡ À§
        if ((y > 0 && bmap[x][y - 1]) || bmap[x][y]) return true;
    }
    //º¸
    else {
        //±âµÕ À§
        if (tmap[x + 1][y] || tmap[x + 1][y + 1]) return true;
        //¾çÂÊ ³¡ÀÌ º¸ À§
        if ((y > 0 && bmap[x][y - 1]) && bmap[x][y + 1]) return true;
    }
    return false;
}

bool canDelete(bool isboard, int x, int y) {
    //±âµÕ
    if (!isboard) {
        tmap[x][y] = false;
        bool flag = false;
        for (int i = 0; i < 9; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (tmap[nx][ny])
                if (!canInstall(isboard, nx, ny)) {
                    flag = true; break;
                }
            if (bmap[nx][ny]) {
                if (!canInstall(!isboard, nx, ny)) {
                    flag = true; break;
                }
            }
        }
        if (flag) {
            tmap[x][y] = true;
            return false;
        }
        tmap[x][y] = true;
    }
    //º¸
    else {
        bmap[x][y] = false;
        bool flag = false;
        for (int i = 0; i < 9; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (tmap[nx][ny])
                if (!canInstall(!isboard, nx, ny)) {
                    flag = true; break;
                }
            if (bmap[nx][ny])
                if (!canInstall(isboard, nx, ny)) {
                    flag = true; break;
                }
        }
        if (flag) {
            bmap[x][y] = true;
            return false;
        }
        bmap[x][y] = true;
    }

    return true;
}

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;

    for (int i = 0; i < build_frame.size(); ++i) {
        int y = build_frame[i][0], x = n - build_frame[i][1];
        bool isboard = build_frame[i][2], install = build_frame[i][3];
        if (install) {
            if (canInstall(isboard, x, y)) {
                if (!isboard) {
                    tmap[x][y] = true;
                }
                else {
                    bmap[x][y] = true;
                }
            }
        }
        else {
            if (canDelete(isboard, x, y)) {
                if (!isboard) {
                    tmap[x][y] = false;
                }
                else {
                    bmap[x][y] = false;
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            if (tmap[i][j] || bmap[i][j]) {
                vector<int> tmp(3, 0);
                tmp[0] = j; tmp[1] = -(i - n);
                if (tmap[i][j]) { tmp[2] = 0; answer.push_back(tmp); }
                if (bmap[i][j]) { tmp[2] = 1; answer.push_back(tmp); }
            }
        }
    sort(answer.begin(), answer.end(), cmp);

    return answer;
}
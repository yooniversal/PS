#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD = 20170805;
const int MAX = 505;

int cache[MAX][MAX][2];
int board[MAX][MAX];
int M, N;

bool OOB(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) return true;
    return false;
}

//prev:: 0: 오른쪽 1:아래
int f(int x, int y, int prev) {
    if (OOB(x, y)) return 0;
    if (board[x][y] == 1) return 0;
    if (x == M - 1 && y == N - 1) return 1;
    int& ret = cache[x][y][prev];
    if (ret != -1) return ret;

    ret = 0;
    if (board[x][y] == 2) {
        if (prev == 1) ret += f(x + 1, y, 1) % MOD;
        else ret += f(x, y + 1, 0) % MOD;
    }
    else
        ret += (f(x + 1, y, 1) % MOD + f(x, y + 1, 0) % MOD) % MOD;
    ret %= MOD;

    return ret;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(cache, -1, sizeof(cache));
    M = m; N = n;

    for (int i = 0; i < city_map.size(); ++i)
        for (int j = 0; j < city_map[i].size(); ++j)
            board[i][j] = city_map[i][j];

    return f(0, 0, 0);
}
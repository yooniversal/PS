#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 101;
const int MOD = 1000000007;
typedef long long ll;

ll cache[MAX][MAX];
bool puddle[MAX][MAX];
int M, N;
int dx[] = { 0, 1 }, dy[] = { 1, 0 };

bool OOB(int x, int y) {
    if (x <= 0 || x > M || y <= 0 || y > N) return true;
    return false;
}

ll f(int x, int y) {
    if (x == M && y == N) return 1;
    ll& ret = cache[x][y];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) continue;
        if (puddle[nx][ny]) continue;
        ret += f(nx, ny) % MOD;
    }
    ret %= MOD;
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(cache, -1, sizeof(cache));
    M = m; N = n;

    for (int i = 0; i < puddles.size(); ++i)
        puddle[puddles[i][0]][puddles[i][1]] = true;

    return f(1, 1);
}
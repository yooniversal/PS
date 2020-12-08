#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
int a[1001][1001];
int dx[] = { 1,0,-1 }, dy[] = { 0,1,-1 };

bool OOB(int x, int y) { return x<1 || x>N || y > x || y > N || a[x][y]; }

void solve(int x, int y, int cnt, int d) {
    a[x][y] = cnt;
    int nx = x + dx[d], ny = y + dy[d];
    if (!OOB(nx, ny)) solve(nx, ny, cnt + 1, d);
    else
        for (int i = 0; i < 3; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            solve(nx, ny, cnt + 1, i);
        }
}

vector<int> solution(int n) {
    N = n;
    vector<int> answer;

    solve(1, 1, 1, 0);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            answer.push_back(a[i][j]);

    return answer;
}
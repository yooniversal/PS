#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ret;
int N;
int ban[13][13];
bool col[13];

bool OOB(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return true;
    return false;
}

void dfs(int r, int c) {
    if (r == N - 1) {
        ++ret;
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (col[i]) continue;
        if (ban[r + 1][i] > 0) continue;
        for (int j = 0; j < N; ++j) {
            if (!OOB(r + 1 + j, i + j)) ++ban[r + 1 + j][i + j];
            if (!OOB(r + 1 + j, i - j)) ++ban[r + 1 + j][i - j];
        }
        col[i] = true;
        dfs(r + 1, i);
        col[i] = false;
        for (int j = 0; j < N; ++j) {
            if (!OOB(r + 1 + j, i + j)) --ban[r + 1 + j][i + j];
            if (!OOB(r + 1 + j, i - j)) --ban[r + 1 + j][i - j];
        }
    }
}

int solution(int n) {
    N = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!OOB(j, i + j)) ++ban[j][i + j];
            if (!OOB(j, i - j)) ++ban[j][i - j];
        }
        col[i] = true;
        dfs(0, i);
        col[i] = false;
        for (int j = 0; j < n; ++j) {
            if (!OOB(j, i + j)) --ban[j][i + j];
            if (!OOB(j, i - j)) --ban[j][i - j];
        }
    }

    return ret;
}
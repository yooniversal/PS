#include <bits/stdc++.h>

int ret;

void dfs(int cur, int plus) {
    if (cur<1 || pow(3, plus / 2) > cur) return;
    if (cur == 3 && plus == 2) {
        ++ret;
        return;
    }

    if (plus >= 2 && cur % 3 == 0) dfs(cur / 3, plus - 2);
    dfs(cur - 1, plus + 1);
}

int solution(int n) {
    ret = 0;
    dfs(n, 0);
    return ret;
}
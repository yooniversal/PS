#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 987654321;

int cache[201][201];

int f(int l, int r, const vector<vector<int>>& a) {
    if (l == r) return 0;
    int& ret = cache[l][r];
    if (ret != -1) return ret;
    ret = INF;
    for (int m = l; m < r; ++m) {
        ret = min(ret, f(l, m, a) + f(m + 1, r, a) + a[l][0] * a[m][1] * a[r][1]);
    }
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(cache, -1, sizeof(cache));

    return f(0, matrix_sizes.size() - 1, matrix_sizes);
}
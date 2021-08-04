#include <vector>
#include <algorithm>
using namespace std;

long long f(int cur, int P, int Q, const vector<vector<int>>& land) {
    long long ret = 0;
    for (int i = 0; i < land.size(); ++i) for (int j = 0; j < land[0].size(); ++j) {
        if (cur < land[i][j]) ret += 1LL * (land[i][j] - cur) * Q;
        else if (cur > land[i][j]) ret += 1LL * (cur - land[i][j]) * P;
    }
    return ret;
}

int binary_search(int l, int r, int P, int Q, const vector<vector<int>>& land) {
    long long ret = 0;
    while (l <= r) {
        long long m = (l + r) / 2, L = f(m, P, Q, land), R = f(m + 1, P, Q, land);
        if (L > R)
            l = m + 1;
        else {
            r = m - 1;
            ret = m;
        }
    }
    return ret;
}

long long solution(vector<vector<int>> land, int P, int Q) {

    int lf = 1000000000, hf = -1;
    for (int i = 0; i < land.size(); ++i) for (int j = 0; j < land[0].size(); ++j) {
        lf = min(lf, land[i][j]);
        hf = max(hf, land[i][j]);
    }

    int Floor = binary_search(lf, hf, P, Q, land);
    return f(Floor, P, Q, land);
}
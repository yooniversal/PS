#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int INF = 987654321;
int dp[20001];

bool match(const string& a, const string& b, int p) {
    for (int i = p, j = 0; i < a.size() && j < b.size(); ++i, ++j) {
        if (a[i] != b[j]) return false;
        if (j == b.size() - 1) return true;
    }
    return false; //길이가 모자란 경우
}

int solution(vector<string> strs, string t)
{
    for (int i = 0; i < 20001; ++i) dp[i] = INF;
    for (int i = 0; i < strs.size(); ++i) {
        if (match(t, strs[i], 0))
            dp[strs[i].size()] = 1;
    }

    for (int i = 1; i < t.size(); ++i) {
        if (dp[i] == INF) continue;
        for (int j = 0; j < strs.size(); ++j) {
            if (!match(t, strs[j], i)) continue;
            dp[i + strs[j].size()] = min(dp[i + strs[j].size()], dp[i] + 1);
        }
    }

    if (dp[t.size()] != INF) return dp[t.size()];
    return -1;
}
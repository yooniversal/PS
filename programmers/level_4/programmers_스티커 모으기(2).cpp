#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int dp[1000001][2];

int solution(vector<int> sticker) {
    int n = sticker.size();
    dp[0][0] = sticker[0];
    dp[1][0] = sticker[0];
    dp[1][1] = sticker[1];
    for (int i = 2; i < n; ++i) {
        dp[i][0] = max(dp[i - 2][0] + sticker[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 2][1] + sticker[i], dp[i - 1][1]);
    }

    if (n >= 2) return max(dp[n - 2][0], dp[n - 1][1]);
    return sticker[0];
}
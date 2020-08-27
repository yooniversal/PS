#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

int dp[100001] = { 0, 1, 1 };

int solve(int n) {
    if (n == 0) return 0;
    if (dp[n]) return dp[n];
    else {
        return dp[n] = (solve(n - 1) % MOD + solve(n - 2) % MOD) % MOD;
    }
}

int solution(int n) {

    return solve(n);
}
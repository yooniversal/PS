#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD = 1234567;

long long cache[2005];

long long f(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    long long& ret = cache[n];
    if (ret != -1) return ret;
    ret = f(n - 1) % MOD + f(n - 2) % MOD;
    ret %= MOD;
    return ret;
}

long long solution(int n) {
    memset(cache, -1, sizeof(cache));
    return f(n);
}
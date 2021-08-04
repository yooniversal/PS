#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long cache[5001], cache2[5001];

long long g(int n);
long long f(int n);

long long solution(int n) {
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	return f(n);
}

long long g(int n) {
	long long& ret = cache2[n];
	if (ret != -1) return ret;
	ret = f(n - 1) % MOD + g(n - 2) % MOD;
	ret %= MOD;
	return ret;
}

long long f(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	long long& ret = cache[n];
	if (ret != -1) return ret;
	ret = f(n - 2) % MOD + 2 * g(n - 1) % MOD;
	ret %= MOD;
	return ret;
}
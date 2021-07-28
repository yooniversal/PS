#include <string>
#include <cstring>
#include <vector>
#define MAX 60001
#define MOD 1000000007

using namespace std;

int cache[MAX];

int f(int cur) {
	if (cur <= 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret % MOD;
	ret = (f(cur - 1) + f(cur - 2)) % MOD;
	return ret;
}

int solution(int n) {

	memset(cache, -1, sizeof(cache));
	cache[1] = 1; cache[2] = 2;

	return f(n);
}
//10844

#include <stdio.h>
#include <stdlib.h>
#define mod 1000000000

long long int dp[101][10];

long long int sol(int n, int i) {

	if (n == 1 && i == 0) return 0;
	else if (n == 1) return 1;
	if (n < 1) return 0;
	if (i < 0 || i>9) return 0;

	if (dp[n][i]) return dp[n][i];
	else {
		if (i == 0) dp[n][i] = sol(n - 1, i + 1);
		else if (i == 9) dp[n][i] = sol(n - 1, i - 1);
		else dp[n][i] = (sol(n - 1, i - 1) + sol(n - 1, i + 1)) % mod;
	}
	

	return dp[n][i];
}

int main() {
	int n, i, j;
	long long int ans = 0;

	scanf("%d", &n);

	//for (i = 0; i < 10; i++)
	//	printf("dp[%d][%d] = %lld\n", n, i, sol(n, i));

	for (i = 0; i <= 9; i++) {
		ans += sol(n, i);
		ans %= mod;
	}

	printf("%lld", ans);

	return 0;

}
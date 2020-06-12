//11051

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1001][1001];

int dyna(int n, int r) {

	if (r == 0 || r == n) {
		dp[n][r] = 1;
		return dp[n][r];
	}

	if (dp[n][r]) return dp[n][r];
	else {
		dp[n][r] = (dyna(n - 1, r - 1)%10007 + dyna(n - 1, r) % 10007) % 10007;
		return dp[n][r];
	}
}

int main() {

	int n, r;

	scanf("%d", &n);
	scanf("%d", &r);

	
	dp[0][0] = dp[1][1] = 1;
	dp[2][0] = dp[2][2] = 1;
	dp[2][1] = 2;

	printf("%d", dyna(n, r));

	return 0;
}
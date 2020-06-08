//2163

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[301][301];

//큰 값 찾기
int maxval(int a, int b) {
	if (a >= b) return a;
	else return b;
}

//DP 이용
int dyna(int m, int n) {
	int temp;

	if (m == 1 && n == 1) return 0;
	//이미 있는 값 이용하기
	if (dp[m][n]) return dp[m][n];
	else {
		if (n != 1)
			temp = dyna(m, 1) + dyna(m, n - 1) + 1;
		else
			temp = dyna(1, n) + dyna(m - 1, n) + 1;

		dp[m][n] = temp;

		return dp[m][n];
	}
}

int main() {
	int m, n;

	scanf("%d %d", &m, &n);

	dp[1][1] = 0;
	dp[2][1] = dp[1][2] = 1;
	dp[3][1] = dp[1][3] = 2;
	dp[2][2] = 3;

	printf("%d", dyna(m, n));

	return 0;
}
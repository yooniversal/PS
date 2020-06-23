//1149

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value_dp[1001][3];

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

int main() {

	int N, arr[1001][3], i, j, temp, mintemp;

	scanf("%d", &N);

	//input
	for (i = 1; i <= N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);

	value_dp[1][0] = arr[1][0];
	value_dp[1][1] = arr[1][1];
	value_dp[1][2] = arr[1][2];

	for (i = 2; i <= N; i++) {
		value_dp[i][0] = min(value_dp[i - 1][1], value_dp[i - 1][2]) + arr[i][0];
		value_dp[i][1] = min(value_dp[i - 1][0], value_dp[i - 1][2]) + arr[i][1];
		value_dp[i][2] = min(value_dp[i - 1][0], value_dp[i - 1][1]) + arr[i][2];
	}

	mintemp = value_dp[N][0];
	for (i = 0; i < 3; i++)
		if (mintemp > value_dp[N][i])
			mintemp = value_dp[N][i];

	printf("%d", mintemp);

	return 0;
}
//1932

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int dp[501][501];

long long int maximum(long long int a, long long int b) {
	if (a <= b) return b;
	else return a;
}

int main() {

	int N, i, j;
	long long int maxtemp;

	long long int** arr = malloc(sizeof(long long int*) * 501);

	for (i = 0; i < 501; i++)
		arr[i] = malloc(sizeof(long long int) * 501);

	scanf("%d", &N);

	//input
	for (i = 1; i <= N; i++)
		for (j = 0; j < i; j++)
			scanf("%lld", &arr[i][j]);

	dp[1][0] = arr[1][0];

	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[i][i-1] = dp[i - 1][i-2] + arr[i][i-1];
		for (j = 1; j <= i - 2; j++) {
			dp[i][j] = maximum(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	maxtemp = dp[N][0];
	for (i = 0; i < N; i++) {
		if (maxtemp < dp[N][i])
			maxtemp = dp[N][i];
	}

	printf("%lld", maxtemp);

	for (i = 0; i < 500; i++)
		free(arr[i]);
	free(arr);

	return 0;
}
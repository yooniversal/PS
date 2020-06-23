//1912

#include <stdio.h>
#include <stdlib.h>

int dynamic_pibo(int N, int col, int** dp) {

	int row = N;

	if (dp[row][col] != NULL) return dp[row][col];
	else {
		dp[row][col] = dp[row / 2][col] + dp[row - row / 2][row / 2 + col];
		return dp[row][col];
	}
}

int getvalue(int N, int** dp) {
	int i, j, max;
	int* a = malloc(sizeof(int) * (N + 1));

	for (j = 1; j <= N; j++) {
		max = dynamic_pibo(N, j, dp);
		printf("***%d\n", dynamic_pibo(N, 1, dp));
		for (i = 2; i <= strlen(dp[N]) - 1; i++)
			if (max < dynamic_pibo(N, i, dp))
				max = dynamic_pibo(N, i, dp);

		a[j] = max;
	}

	max = a[1];
	for (i = 1; i <= N; i++)
		if (max < a[i])
			max = a[i];

	free(a);

	return max;
}

int main() {

	int N, i, temp;

	scanf("%d", &N);

	int** dp = malloc(sizeof(int) * (N + 1));
	for (i = 1; i <= N; i++)
		*(dp + i) = malloc(sizeof(int) * (N - i + 1) + 1);

	for (i = 1; i <= N; i++)
		scanf("%d", &dp[N][i]);

	printf("what ~~ %d\n", dynamic_pibo(2, 1, dp));
	printf("%d\n", getvalue(N, dp));

	for (i = 1; i <= N; i++)
		free((dp + i));
	free(dp);

	return 0;
}
//2163

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a)>(b))?(a):(b))

int dp[3][100001];
int arr[3][100001];

int main() {
	int n, i, j, T;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);

		for(i=1; i<=2; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &arr[i][j]);

		dp[1][0] = dp[2][0] = 0;
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];

		for (i = 2; i <= n; i++) {
			dp[1][i] = max(dp[2][i-1], dp[2][i - 2]) + arr[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[2][i];
		}

		printf("%d\n", max(dp[1][n], dp[2][n]));
	}

	return 0;
}
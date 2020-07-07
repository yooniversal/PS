//2579

#include <stdio.h>
#include <stdlib.h>

long long int dp[301];

long long int maximum(long long int a, long long int b) {
	if (a <= b) return b;
	else return a;
}

long long int sol(long long int* arr, int n) {

	if (n == 0) {
		dp[0] = 0;
		return dp[0];
	}
	if (n == 1) {
		dp[1] = arr[1];
		return dp[1];
	}
	if (n == 2) {
		dp[2] = maximum(arr[2], sol(arr, 1) + arr[2]);
	}

	if (dp[n]) return dp[n];
	else {
		dp[n] = maximum((sol(arr, n-3) + arr[n - 1] + arr[n]), (sol(arr, n-2) + arr[n]));
		return dp[n];
	}
}

int main() {
	int n, i;
	long long int arr[301];

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	printf("%lld", sol(arr, n));

	return 0;

}
//2156

#include <stdio.h>
#include <stdlib.h>

long long int dp[10001];
long long int arr[10001];

long long int maximum3(long long int a, long long int b, long long int c) {
	if (a < b)
		if (b < c) return c;
		else return b;
	else
		if (a < c) return c;
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
		dp[2] = arr[1] + arr[2];
		return dp[2];
	}
	if (n == 3) {
		dp[3] = maximum3(arr[1] + arr[2], arr[1] + arr[3], arr[2] + arr[3]);
		return dp[3];
	}
	if (n == 4) {
		dp[4] = maximum3(arr[1] + arr[2] + arr[4], arr[1] + arr[3] + arr[4], arr[2] + arr[3]);
		return dp[4];
	}

	if (dp[n]) return dp[n];
	else {
		dp[n] = maximum3((sol(arr, n - 2) + arr[n]), sol(arr, n - 1), sol(arr, n - 3) + arr[n - 1] + arr[n]);
		return dp[n];
	}
}

int main() {

	int n, i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	printf("%lld", sol(arr, n));

	return 0;

}
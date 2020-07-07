//11052

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1001] = { 0, };
int cnt = 0;

int maxval(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int dyna(int* arr, int n) {
	int i, max, temp;

	if (dp[n]) return dp[n];
	else {
		for (i = 1; i <= n / 2; i++) {
			temp = dyna(arr, i) + dyna(arr, n - i);
			if (i == 1) max = temp;
			else {
				if (max < temp)
					max = temp;
			}
		}

		dp[n] = maxval(max, arr[n]);

		return dp[n];
	}
}



int main() {
	int n, i;

	scanf("%d", &n);
	int arr[1001] = { 0, };

	//input
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];

	printf("%d", dyna(arr, n));

	return 0;
}
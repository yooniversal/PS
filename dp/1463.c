//1463

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1000001] = { 0, 0, 1, 1, 2, 3, 2, 3, 3, 2, 3 };

int min3(int a, int b, int c) {
	int arr[3], min, i;

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	min = arr[0];
	for (i = 0; i < 3; i++)
		if (min > arr[i])
			min = arr[i];

	return min;
}
int dpfunc(int n) {
	int i, temp[3], a, b, c;

	for (i = 0; i < 3; i++)
		temp[i] = n;

	if (n == 0 || n == 1) return 0;

	if (dp[n]) return dp[n];
	else {
		if (n % 3 == 0) {
			temp[0] /= 3;
			a = dpfunc(temp[0]) + 1;
		}
		else
			a = 99999;

		if (n % 2 == 0) {
			temp[1] /= 2;
			b = dpfunc(temp[1]) + 1;
		}
		else
			b = 99999;

		temp[2] -= 1;
		c = dpfunc(temp[2]) + 1;

		dp[n] = min3(a, b, c);
		return dp[n];
	}
}

int main() {
	int n;

	scanf("%d", &n);

	printf("%d", dpfunc(n));

	return 0;
}
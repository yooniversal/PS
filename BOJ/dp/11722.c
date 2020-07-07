//11722

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1001] = { 0, };
int a[1001] = { 0, };

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int maxindex(int* arr) {
	int i, index, max;

	max = arr[0];
	index = 0;
	for (i = 0; i <= leng(arr); i++)
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}

	return index;
}
int leng(int* arr) {
	int i;

	for (i = 1; i < 1001; i++)
		if (arr[i] == 0)
			return i - 1;

	return i - 1;
}

int searchindex(int key) {
	int i;
	int n = leng(a);

	for (i = 1; i < n; i++)
		if (a[i - 1] < key && key <= a[i])
			return i;

	return n;
}

int dpfunc(int* arr, int n) {
	int i, j;

	if (dp[1] == 0) {
		dp[1] = 1;
		a[1] = arr[1];
		return a[1];
	}
	else {
		if (searchindex(arr[n]) <= leng(dp) && a[searchindex(arr[n])] >= arr[n])
			a[searchindex(arr[n])] = arr[n];
		else {
			dp[searchindex(arr[n]) + 1] = searchindex(arr[n]) + 1;
			a[searchindex(arr[n]) + 1] = arr[n];
		}
	}
}

void redesign(int* arr, int n) {
	int mid = n / 2, i;

	if (n % 2 == 0) {
		for (i = 1; i <= mid; i++)
			swap(&arr[i], &arr[n - i + 1]);
	}
	else {
		for (i = 1; i <= mid; i++)
			swap(&arr[i], &arr[n - i + 1]);
	}
}

int main() {
	int n, i;

	scanf("%d", &n);
	int arr[1001] = { 0, };

	//input
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0;
	a[0] = 0;

	redesign(arr, n);

	for (i = 1; i <= n; i++)
		dpfunc(arr, i);

	printf("%d", maxindex(dp));

	return 0;
}
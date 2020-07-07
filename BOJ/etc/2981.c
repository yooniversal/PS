//2981

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

long long int arr[100], ans[1000001];

void merge(long long int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	long long int* sorted = malloc(sizeof(int) * 1000001);
	int k;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[index] = arr[i];
			i++;
		}
		else {
			sorted[index] = arr[j];
			j++;
		}
		index++;
	}

	if (i > mid)
		for (k = j; k <= end; k++) {
			sorted[index] = arr[k];
			index++;
		}
	else
		for (k = i; k <= mid; k++) {
			sorted[index] = arr[k];
			index++;
		}

	//copy to arr
	for (k = start; k <= end; k++)
		arr[k] = sorted[k];

	free(sorted);
}

void mergesort(long long int* arr, int p, int q) {
	int n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

long long int gcd(long long int a, long long int b) {

	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {

	int N, M, cnt=0;
	long long int lgcd;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	mergesort(arr, 0, N - 1);

	lgcd = arr[1] - arr[0];
	for (int i = 1; i < N - 1; i++)
		lgcd = gcd(lgcd, arr[i + 1] - arr[i]);

	for (long long int j = 1; j*j <= lgcd; j++) {
		if (lgcd % j == 0) {
			ans[cnt] = j;
			cnt++;
			if (j != lgcd / j) {
				ans[cnt] = lgcd / j;
				cnt++;
			}
		}
	}

	mergesort(ans, 0, cnt-1);
	
	for (int i = 0; i <= cnt - 1; i++)
		if(ans[i] != 1)
			printf("%d ", ans[i]);

	return 0;
}
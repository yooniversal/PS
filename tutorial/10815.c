//10815

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

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
	long long int n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

int searchindex(long long int* arr, long long int key, int start, int end) {
	int mid, temp = end, stemp = start;

	if (end == 1)
		if (arr[end] == key) return 1;
		else return 0;

	while (end - start > 0) {
		mid = (start + end) / 2;
		//printf("start : %d  end : %d  mid : %d  key : %lld  arr[%d] : %lld\n", start, end, mid, key, mid, arr[mid]);

		if (arr[mid] == key) return 1;
		else if (arr[mid] >= key) end = mid;
		else start = mid + 1;
	}

	if (arr[temp] == key || arr[stemp] == key) return 1;
	else return 0;
}

int main() {
	int i, n, co;
	long long int* arr = malloc(sizeof(long long int) * 1000001);
	long long int* brr = malloc(sizeof(long long int) * 1000001);

	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%lld", &arr[i]);

	mergesort(arr, 1, n);

	scanf("%d", &co);

	for (i = 1; i <= co; i++)
		scanf("%lld", &brr[i]);

	for (i = 1; i <= co; i++)
		printf("%d ",searchindex(arr, brr[i], 1, n));

	free(brr);
	free(arr);

	return 0;
}
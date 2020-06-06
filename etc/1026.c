//1026

#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 51);
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

void mergesort(int* arr, int p, int q) {
	int i, j, n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

void minmerge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 51);
	int k;

	while (i <= mid && j <= end) {
		if (arr[i] >= arr[j]) {
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

void minmergesort(int* arr, int p, int q) {
	int i, j, n;

	if (p < q) {
		n = (p + q) / 2;

		minmergesort(arr, p, n);
		minmergesort(arr, n + 1, q);
		minmerge(arr, p, n, q);
	}
}

int main() {
	int n, i, ans=0;
	
	scanf("%d", &n);

	int* a = malloc(sizeof(int) * (n + 1));
	int* b = malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	mergesort(a, 0, n - 1);
	minmergesort(b, 0, n - 1);

	/*
	printf("a : ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	printf("b : ");
	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
	*/

	for (i = 0; i < n; i++)
		ans += a[i] * b[i];

	printf("%d", ans);

	free(b);
	free(a);

	return 0;
}
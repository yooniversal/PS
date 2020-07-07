//1037

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a)>(b))?(a):(b))

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

int main() {
	int n, i, j;

	scanf("%d", &n);
	long long int* a = malloc(sizeof(long long int) * n);

	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	mergesort(a, 0, n - 1);

	if (n > 1)
		printf("%lld", a[0] * a[n - 1]);
	else
		printf("%lld", a[0] * a[0]);

	free(a);

	return 0;
}
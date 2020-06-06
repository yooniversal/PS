//10816

#include <stdio.h>
#include <stdlib.h>

int value;
int index = -1;

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 500001);
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

int lowerBound(int* array, int value, int low, int high) {
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (value <= array[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

int upperBound(int* array, int value, int low, int high) {

	if (value == array[high]) return high + 1;

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (value >= array[mid]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return low;
}



int main() {
	int n, m, i, cnt1 = 0, cnt2 = 0, plusindex=0, minusindex=1, temp;

	scanf("%d", &n);

	int* a = malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &m);

	int* b = malloc(sizeof(int) * (m + 1));

	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);

	mergesort(a, 0, n - 1);
	
	for (i = 0; i < m; i++)
		printf("%d ", upperBound(a, b[i], 0, n - 1) - lowerBound(a, b[i], 0, n - 1));

	free(a);

	return 0;
}
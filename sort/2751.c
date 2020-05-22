//2751

#include <stdio.h>

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 1000001);
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
		n = (p+q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

int main() {

	int T, i;

	scanf("%d", &T);
	int* arr = malloc(sizeof(int) * T);

	//input
	for (i = 0; i < T; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, T-1);

	for (i = 0; i < T; i++)
		printf("%d\n", arr[i]);

	free(arr);

	return 0;
}
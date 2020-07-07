//2750

#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* arr, int length) {
	int i, j, min, min_index=0;

	min = arr[0];
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (min > arr[j]) {
				min = arr[j];
				min_index = j;
			}
		}

		//printf("%d %d\n", min, min_index);
		if(min_index != 0)
			if (arr[i] > arr[min_index])
				swap(&arr[i], &arr[min_index]);

		min = arr[i+1];
		min_index = 0;
	}
}

int main() {

	int T, arr[1001], i;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
		scanf("%d", &arr[i]);

	sort(arr, T);

	for (i = 0; i < T; i++)
		printf("%d\n", arr[i]);

	return 0;
}
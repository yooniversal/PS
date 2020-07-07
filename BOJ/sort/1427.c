//1427

#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* arr, int length) {
	int i, j, max, max_index = 0;

	max = arr[0];
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (max < arr[j]) {
				max = arr[j];
				max_index = j;
			}
		}

		if (max_index != 0)
			if (arr[i] < arr[max_index])
				swap(&arr[i], &arr[max_index]);

		max = arr[i + 1];
		max_index = 0;
	}
}

int main() {
	int i, input, length=0, temp;

	scanf("%d", &input);
	int* arr = malloc(sizeof(int) * 10);

	temp = input;

	while (temp != 0) {
		temp /= 10;
		length++;
	}

	for (i = 0; i < length; i++) {
		arr[i] = input % 10;
		input /= 10;
	}

	sort(arr, length);

	for(i=0; i<length; i++)
		printf("%d", arr[i]);

	free(arr);

	return 0;
}
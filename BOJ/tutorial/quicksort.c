void quicksort(int arr[], int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);

		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int partition(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = (l - 1);
	int j;

	for (j = 1; j <= r - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
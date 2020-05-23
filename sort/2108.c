//2108

#include <stdio.h>

int abs(int a) {
	if (a < 0)
		return a * (-1);
	else
		return a;
}

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
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int func1(int *arr, int n) {
	int i, sum = 0;

	for (i = 0; i < n; i++)
		sum += arr[i];

	if (sum > 0) {
		if ((double)(sum % n) / (double)n < 0.5) return sum / n;
		else return sum / n + 1;
	}
	else {
		if ((double)(abs(sum) % n) / (double)n < 0.5) return sum / n;
		else return sum / n -1;
	}
}

int func2(int* arr, int n) {
	int i, sum = 0;

	mergesort(arr, 0, n - 1);

	return arr[n/2];
}

int func3(int* arr, int n) {
	int* b = malloc(sizeof(int) * 8001);
	int* ans = malloc(sizeof(int) * 8001);
	int i, temp, max, cnt=0;

	for (i = 0; i <= 8000; i++) {
		b[i] = 0;
		ans[i] = 0;
	}

	for (i = 0; i < n; i++) {
		if (arr[i] == 0)
			b[4000]++;
		else
			b[arr[i] + 4000]++;
	}

	max = b[0];
	for (i = 0; i <= 8000; i++)
		if (max < b[i])
			max = b[i];

	for (i = 0; i <= 8000; i++) {
		if (i == 4000) {
			if (b[i] == max) {
				ans[cnt] = 0;
				cnt++;
			}
		}
		else
			if (b[i] == max) {
				ans[cnt] = i - 4000;
				cnt++;
			}
	}
	
	if (cnt > 1)
		temp = ans[1];
	else
		temp = ans[0];

	free(b);
	free(ans);
	
	return temp;
}

int func4(int* arr, int n) {
	int max, min, i;

	max = arr[0];
	min = arr[0];
	for (i = 0; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	return (max - min);
}

int main() {
	int i, n;

	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d\n", func1(arr, n));
	printf("%d\n", func2(arr, n));
	printf("%d\n", func3(arr, n));
	printf("%d", func4(arr, n));

	free(arr);

	return 0;
}
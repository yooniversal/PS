//1041

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

long long int arr[6];

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

long long int ans(long long int n) {
	long long int max, ans=0;
	
		long long int temp0 = arr[0] * (5 * n * n - 16 * n + 12);
		long long int temp1 = (arr[0]+arr[1]) * (8 * n - 12);
		long long int temp2 = (arr[0]+arr[1]+arr[2]) * 4;

		return temp0 + temp1 + temp2;
	
}

int main() {
	
	long long int n;
	long long int temp, max, anss=0;

	scanf("%lld", &n);

	for (int i = 0; i < 6; i++)
		scanf("%lld", &arr[i]);

	max = arr[0];
	for (int i = 0; i < 6; i++) {
		if (max < arr[i])
			max = arr[i];
		anss += arr[i];
	}
	

	if (arr[0] < arr[5]) temp = arr[0];
	else temp = arr[5];

	arr[0] = temp;

	if (arr[1] < arr[4]) temp = arr[1];
	else temp = arr[4];

	arr[1] = temp;

	if (arr[2] < arr[3]) temp = arr[2];
	else temp = arr[3];

	arr[2] = temp;

	mergesort(arr, 0, 2); 

	if(n==1) printf("%lld", anss -max);
	else printf("%lld", ans(n));

    return 0;
}
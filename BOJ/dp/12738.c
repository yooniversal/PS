//12738

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//lower_bound function : O(logn)
int searchindex(long long int* arr, long long int key, long long int start, long long int end) {
	int i;
	long long int mid = (start + end) / 2;

	if (arr[mid + 1] == NULL) return mid;

	while (end - start > 0) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < key && key <= arr[mid]) return mid;
		else if (arr[mid] >= key) end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {
	int i;
	long long int tempvalue, cnt = 1, n;

	scanf("%lld", &n);
	long long int* arr = malloc(sizeof(long long int) * 1000001);
	arr[0] = 0;

	//initialize first index
	scanf("%lld", &arr[1]);

	//initialize remainder indices
	//dont need to save in array
	//deciding proper position with remainder indices every turn
	//O(nlogn)
	for (i = 2; i <= n; i++) {
		scanf("%lld", &tempvalue);
		if (arr[cnt] < tempvalue) {
			arr[++cnt] = tempvalue;
		}
		else {
			arr[searchindex(arr, tempvalue, 1, cnt)] = tempvalue;
		}
	}

	printf("%lld", cnt);

	free(arr);

	return 0;
}
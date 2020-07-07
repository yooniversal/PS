//13900

#include <stdio.h>

int main() {
	int n, i, j;
	long long int ans = 0, tempsum = 0;

	scanf("%d", &n);
	long long int* arr = malloc(sizeof(long long int) * n);

	for (i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	for (i = 0; i < n; i++)
		tempsum += arr[i];

	for (i = 0; i < n - 1; i++) {
		tempsum -= arr[i];
		ans += arr[i] * tempsum;
	}

	printf("%lld", ans);

	free(arr);

	return 0;
}
//11047

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))

int main() {

	int n, k, cnt=0, point;
	int arr[10];

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	while (k != 0) {
		for (point = n - 1; point >= 0; point--) {
			if (k == 0) break;
			if (k >= arr[point]) {
				cnt += k / arr[point];
				k %= arr[point];
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
//2446

#include <stdio.h>

int main() {

	int i, j, k, n;

	scanf("%d", &n);

	for (i = n; i >= 1; i--) {
		for (k = 0; k < n - i; k++) printf(" ");
		for (j = 2 * i - 1; j >= 1; j--) printf("*");
		printf("\n");
	}
	for (i = 2; i <= n; i++) {
		for (k = n-i; k > 0; k--) printf(" ");
		for (j = 1; j <= 2*i-1; j++) printf("*");
		printf("\n");
	}

	return 0;
}
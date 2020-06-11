//11653

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			if (n % i == 0) {
				printf("%d\n", i); 
				n /= i;
				if (i == n) {
					printf("%d\n", i);
					return 0;
				}
			}
		}
	}


	return 0;
}
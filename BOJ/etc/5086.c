//5086

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int n, m;

	while (1) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0) return;

		if (m % n == 0) printf("factor\n");
		else if (n % m == 0) printf("multiple\n");
		else printf("neither\n");
	}


	return 0;
}
//2522

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int n, n1, i, temp, row1;
	row1 = 1;

	scanf("%d", &n);

	temp = n - 1;
	n1 = n - 1;

	while (n != 0) {
		for (i = 0; i < temp; i++)
			printf(" ");
		for (i = 0; i < row1; i++)
			printf("*");
		printf("\n");

		row1++;
		temp--;
		n--;
	}

	temp = n1;
	row1 = 1;

	while (n1 != 0) {
		for (i = 0; i < row1; i++)
			printf(" ");
		for (i = 0; i < n1; i++)
			printf("*");
		printf("\n");

		row1++;
		n1--;
	}

	return 0;
}
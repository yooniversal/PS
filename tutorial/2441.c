//2440

#include <stdio.h>

int main() {
	int a, temp, i, j;

	scanf("%d", &a);
	temp = a;

	while (a != 0) {
		for (j = 0; j < temp-a; j++)
			printf(" ");
		for (i = 1; i <= a; i++) {
			printf("*");
		}
		printf("\n");

		a--;
	}

	return 0;
}
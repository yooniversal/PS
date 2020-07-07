//2440

#include <stdio.h>

int main() {
	int a, i;

	scanf("%d", &a);

	while (a != 0) {
		for (i = 0; i < a; i++)
			printf("*");
		printf("\n");

		a--;
	}

	return 0;
}
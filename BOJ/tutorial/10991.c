//10991

#include <stdio.h>

int main() {
	int a, b = 0, cnt, i, j;

	scanf("%d", &a);
	cnt = 1;

	while (a != 0) {
		for (j = 0; j < a - 1; j++)
			printf(" ");
		printf("*");

		for (j = 0; j < b; j++)
			printf(" *");

		printf("\n");

		a--;
		b++;
		cnt++;
	}

	return 0;
}
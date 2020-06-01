//2442

#include <stdio.h>

int main() {
	int a, b=0, c, cnt, i, j;

	scanf("%d", &a);
	cnt = 1;
	c = a;

	while (a != 0) {
		if (a != 1) {
			for (j = 0; j < a - 1; j++)
				printf(" ");
			printf("*");

			for (j = 0; j < 2 * b - 1; j++)
				printf(" ");

			if (cnt != 1)
				printf("*");
		}
		else
			for (i = 0; i < 2 * c - 1; i++)
				printf("*");

		printf("\n");

		a--;
		b++;
		cnt++;
	}

	return 0;
}
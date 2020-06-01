//10995

#include <stdio.h>

int main() {
	int a, b, cnt, i, j;

	scanf("%d", &a);
	cnt = 1;
	b = a;

	while (a != 0) {
		if (cnt % 2 == 0)
			printf(" ");
		for (j = 0; j < b; j++)
			printf("* ");

		printf("\n");

		a--;
		cnt++;
	}

	return 0;
}
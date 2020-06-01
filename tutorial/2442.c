//2442

#include <stdio.h>

int main() {
	int a, cnt, i, j;

	scanf("%d", &a);
	cnt = 1;

	while (a != 0) {
		for (j = 0; j < a-1; j++)
			printf(" ");
		for (i = 1; i <= 2*cnt-1; i++) {
			printf("*");
		}
		printf("\n");

		a--;
		cnt++;
	}

	return 0;
}
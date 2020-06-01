//2443

#include <stdio.h>

int main() {
	int a, cnt, i, j, temp;

	scanf("%d", &a);
	cnt = a;
	temp = 1;

	while (a != 0) {
		for (j = 0; j < temp-1; j++)
			printf(" ");
		for (i = 1; i <= 2 * cnt - 1; i++) {
			printf("*");
		}
		printf("\n");

		a--;
		cnt--;
		temp++;
	}

	return 0;
}
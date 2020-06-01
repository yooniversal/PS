//2444

#include <stdio.h>

int main() {
	int a, b, cnt, i, j, temp, temp1, cnt1=1;

	scanf("%d", &a);
	cnt = a;
	temp = 1;
	b = a-1;
	temp1 = b;

	while (b != 0) {
		for (j = 0; j < temp1; j++)
			printf(" ");
		for (i = 1; i <= 2 * cnt1 - 1; i++) {
			printf("*");
		}
		printf("\n");

		b--;
		cnt1++;
		temp1--;
	}

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
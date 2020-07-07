//2445

#include <stdio.h>

int main() {
	int n, i, j, row1 = 1, row2, blk, n2;

	scanf("%d", &n);

	blk = 1;
	n2 = n-1;
	row2 = n - 1;
	
	while (n != 0) {
		for (i = 0; i < row1; i++)
			printf("*");
		for (i = 2; i < 2 * n; i++)
			printf(" ");
		for (i = 0; i < row1; i++)
			printf("*");
		printf("\n");

		row1++;
		n--;
	}
	while (n2 != 0) {

		for (i = 0; i < row2; i++)
			printf("*");
		for (i = 0; i < 2 * blk; i++)
			printf(" ");
		for (i = 0; i < row2; i++)
			printf("*");
		printf("\n");


		row2--;
		blk++;
		n2--;
	}

	return 0;
}
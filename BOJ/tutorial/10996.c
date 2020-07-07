//10996

#include <stdio.h>

void even(int n);
void odd(int n);
int main() {

	int n;

	scanf("%d", &n);

	if (!(n % 2))
		even(n);
	else
		odd(n);

	return 0;
}

void even(int n) {
	int i, j;

	for (j = 0; j < n; j++) {
		for (i = 1; i <= n / 2; i++)
			printf("* ");
		printf("\n");
		for (i = 1; i <= n / 2; i++)
			printf(" *");
		printf("\n");
	}
}

void odd(int n) {

	int i, j;

	for (j = 0; j < n; j++) {
		for (i = 1; i <= (n+1) / 2; i++)
			printf("* ");
		printf("\n");
		for (i = 1; i <= (n + 1) / 2 - 1; i++)
			printf(" *");
		printf("\n");
	}
}
//10952

#include <stdio.h>

int main() {

	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);

		if (a != 0 || b != 0) printf("%d\n", a + b);
		else return 0;
	}

	return 0;
}
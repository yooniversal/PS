//2438

#include <stdio.h>

int main() {
	int i, x, z;

	scanf("%d", &i);

	for (x = 1; x <= i; x++)
	{

		for (z = 1; z <= x; z++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
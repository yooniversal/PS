//5543

#include <stdio.h>

int main() {

	int a[3], b[2], i, min1, min2;

	for (i = 0; i < 3; i++) scanf("%d", &a[i]);
	for (i = 0; i < 2; i++) scanf("%d", &b[i]);
	
	min1 = a[0];
	min2 = b[0];

	for (i = 0; i < 3; i++)
		if (a[i] < min1) min1 = a[i];
	for (i = 0; i < 2; i++)
		if (b[i] < min2) min2 = b[i];

	printf("%d", min1 + min2 - 50);

	return 0;
}
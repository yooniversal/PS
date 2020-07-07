//10817

#include <stdio.h>

int main() {

	int a[3],i, j, min, temp;

	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	for (j = 0; j < 2; j++) {
		for (i = j + 1; i < 3; i++) {
			if (a[i] < a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	
		printf("%d", a[1]);

	return 0;
}
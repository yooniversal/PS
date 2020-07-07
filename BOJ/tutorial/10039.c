//10039

#include <stdio.h>

int main() {

	int n[5], i, result = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &n[i]);
		if (n[i] < 40) n[i] = 40;
		result += n[i];
	}

	printf("%d", result / 5);

	return 0;
}
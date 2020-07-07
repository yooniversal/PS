//10828

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int n, i, point = -1;
	char input[6];

	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n+1);

	for (i = 0; i < n; i++) {
		scanf("%s", input);

		if (!strcmp("push", input)) {
			scanf("%d", &arr[++point]);
		}
		else if (!strcmp("pop", input)) {
			if (point != -1) {
				printf("%d\n", arr[point]);
				point--;
			}
			else
				printf("-1\n");
		}
		else if (!strcmp("size", input))
			printf("%d\n", point + 1);
		else if (!strcmp("empty", input))
			if (point != -1) printf("0\n");
			else printf("1\n");
		else
			if (point != -1)
				printf("%d\n", arr[point]);
			else
				printf("-1\n");

		memset(input, NULL, sizeof(input));
	}

	free(arr);

	return 0;
}
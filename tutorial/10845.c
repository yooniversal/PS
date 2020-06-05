//10845

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int n, i, frontpoint = -1, backpoint = -1;
	char input[6];

	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * 2*n + 1);

	for (i = 0; i < n; i++) {
		scanf("%s", input);

		if (!strcmp("push", input)) {
			scanf("%d", &arr[++backpoint]);
			if (frontpoint == -1)
				frontpoint++;
		}
		else if (!strcmp("pop", input)) {

			if (frontpoint == -1) printf("-1\n");
			else if (frontpoint <= backpoint) {
				printf("%d\n", arr[frontpoint]);
				frontpoint++;
			}
			else
				printf("-1\n");
		}
		else if (!strcmp("size", input))
			if (frontpoint == -1) printf("0\n");
			else if (frontpoint < backpoint)
				printf("%d\n", backpoint - frontpoint + 1);
			else if (frontpoint == backpoint)
				printf("1\n");
			else
				printf("0\n");
		else if (!strcmp("empty", input))
			if (frontpoint == -1) printf("1\n");
			else if (frontpoint <= backpoint) printf("0\n");
			else printf("1\n");
		else if(!strcmp("front", input))
			if (frontpoint == -1) printf("-1\n");
			else if (frontpoint <= backpoint)
				printf("%d\n", arr[frontpoint]);
			else
				printf("-1\n");
		else
			if (frontpoint == -1) printf("-1\n");
			else if (frontpoint <= backpoint)
				printf("%d\n", arr[backpoint]);
			else
				printf("-1\n");

		memset(input, NULL, sizeof(input));
	}

	free(arr);

	return 0;
}
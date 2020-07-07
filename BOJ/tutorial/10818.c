//10818

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n, i, min, max;

	scanf("%d", &n);

	//dynamic allocation
	int* list = malloc(sizeof(int) * n);

	//allocate value to list
	//do not should input line-by-line
	for (i = 0; i < n; i++)
		scanf("%d", (list + i));

	max = *(list + 0);
	min = *(list + 0);

	for (i = 0; i < n; i++) {
		if (max < *(list + i))
			max = *(list + i);
		if (min > *(list + i))
			min = *(list + i);
	}

	printf("%d %d", min, max);

	free(list);

	return 0;
}


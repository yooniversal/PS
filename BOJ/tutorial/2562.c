//2562

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n=9, i, min, max, keep=0;

	//scanf("%d", &n);

	//dynamic allocation
	int* list = malloc(sizeof(int) * n);

	//allocate value to list
	for (i = 0; i < n; i++)
		scanf("%d", (list + i));

	max = *(list + 0);
	min = *(list + 0);

	for (i = 0; i < n; i++) {
		if (max <= *(list + i)) {
			max = *(list + i);
			keep = i+1;
		}
		/*
		if (min => *(list + i))
			min = *(list + i);
		*/
	}

	printf("%d\n", max);
	printf("%d", keep);

	free(list);

	return 0;
}
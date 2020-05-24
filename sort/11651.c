//11651

#include <stdio.h>
#include <malloc.h>

struct value {
	int x;
	int y;
};

void merge(struct value* val, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	struct value* sorted = malloc(sizeof(struct value) * 1000001);
	int k;

	while (i <= mid && j <= end) {
		if ((val + i)->y <= (val + j)->y) {
			if ((val + i)->y == (val + j)->y) {
				if ((val + i)->x < (val + j)->x) {
					(sorted + index)->y = (val + i)->y;
					(sorted + index)->x = (val + i)->x;
					i++;
				}
				else {
					(sorted + index)->y = (val + j)->y;
					(sorted + index)->x = (val + j)->x;
					j++;
				}
			}
			else {
				(sorted + index)->y = (val + i)->y;
				(sorted + index)->x = (val + i)->x;
				i++;
			}
		}
		else {
			(sorted + index)->y = (val + j)->y;
			(sorted + index)->x = (val + j)->x;
			j++;
		}
		index++;
	}

	if (i > mid)
		for (k = j; k <= end; k++) {
			(sorted + index)->y = (val + k)->y;
			(sorted + index)->x = (val + k)->x;
			index++;
		}
	else
		for (k = i; k <= mid; k++) {
			(sorted + index)->y = (val + k)->y;
			(sorted + index)->x = (val + k)->x;
			index++;
		}

	//copy to struct val
	for (k = start; k <= end; k++) {
		(val + k)->x = (sorted + k)->x;
		(val + k)->y = (sorted + k)->y;
	}

	free(sorted);
}

void mergesort(struct value* val, int p, int q) {
	int i, j, n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(val, p, n);
		mergesort(val, n + 1, q);
		merge(val, p, n, q);
	}
}

int main() {

	int i, input;

	scanf("%d", &input);

	struct value* val = malloc(sizeof(struct value) * input);

	for (i = 0; i < input; i++)
		scanf("%d %d", &(val + i)->x, &(val + i)->y);

	mergesort(val, 0, input - 1);

	for (i = 0; i < input; i++)
		printf("%d %d\n", (val + i)->x, (val + i)->y);


	free(val);

	return 0;
}
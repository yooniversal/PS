//1181

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct value {
	char string[51];
	int length;
};

void merge(struct value* val, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	struct value* sorted = malloc(sizeof(struct value) * 20000);
	int k = 0;

	while (i <= mid && j <= end) {
		if ((val + i)->length <= (val + j)->length) {
			if ((val + i)->length == (val + j)->length) {
				if (strcmp((val + i)->string, (val + j)->string) < 0) {
					strcpy((sorted + index)->string, (val + i)->string);
					(sorted + index)->length = (val + i)->length;
					i++;
				}
				else if (strcmp((val + i)->string, (val + j)->string) > 0) {
					strcpy((sorted + index)->string, (val + j)->string);
					(sorted + index)->length = (val + j)->length;
					j++;
				}
				else {
					strcpy((sorted + index)->string, (val + j)->string);
					(sorted + index)->length = (val + j)->length;
					j++;
				}
			}
			else {
				strcpy((sorted + index)->string, (val + i)->string);
				(sorted + index)->length = (val + i)->length;
				i++;
			}
		}
		else {
			strcpy((sorted + index)->string, (val + j)->string);
			(sorted + index)->length = (val + j)->length;
			j++;
		}
		index++;
	}

	if (i > mid)
		for (k = j; k <= end; k++) {
			strcpy((sorted + index)->string, (val + k)->string);
			(sorted + index)->length = (val + k)->length;
			index++;
		}
	else
		for (k = i; k <= mid; k++) {
			strcpy((sorted + index)->string, (val + k)->string);
			(sorted + index)->length = (val + k)->length;
			index++;
		}

	//copy to struct val
	for (k = start; k <= end; k++) {
		strcpy((val + k)->string, (sorted + k)->string);
		(val + k)->length = (sorted + k)->length;
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

	int i, T;
	struct value *val = malloc(sizeof(struct value)*20000);

	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		scanf("%s", (val + i)->string);
		(val + i)->length = strlen((val + i)->string);
	}

	mergesort(val, 0, T - 1);

	for (i = 0; i < T; i++) {
		printf("%s\n", (val + i)->string);
		while (!strcmp((val + i)->string, (val + i + 1)->string))
			i++;
	}

	free(val);

	return 0;
}
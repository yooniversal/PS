//7568

#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int main() {

	int N, i, j, min1, min2, max1, max2;
	int x[200], y[200], grade[200];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
		grade[i] = 1;
	}

	for (i = 1; i < N; i++) {
		for (j = 0; j <= i - 1; j++) {
			// big
			if (x[j] < x[i] && y[j] < y[i]) {
				grade[j]++;
			}
			// small
			else if (x[j] > x[i] && y[j] > y[i]) {
				grade[i]++;
			}
		}
	}

	for (i = 0; i < N; i++)
		printf("%d\n", grade[i]);

	//printf("%d %d", min1, min2);

	return 0;
}
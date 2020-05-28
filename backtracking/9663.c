//9663

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans = 0;

void queens(int* col, int i, int N) {
	int j;

	if (prom(col, i)) {
		if (i == N-1)
			ans++;
		else
			for (j = 0; j < N; j++) {
				col[i+1] = j;
				queens(col, i+1, N);
			}
	}
}

int prom(int* col, int i) {
	int index = 0;
	int swt = 1;

	while (index < i && swt == 1) {
		if (col[i] == col[index] || abs(col[i] - col[index]) == i - index)
			swt = 0;
		//search all row
		index++;
	}
	return swt;
}

int main() {

	int N;

	scanf("%d", &N);
	int* col = malloc(sizeof(int) * N);

	//col[a]=b <- Get value where row:a, col:b
	queens(col, -1, N);

	printf("%d", ans);

	free(col);

	return 0;
}
//15649

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int index, int* posit, int N, int M) {
	int j;

	if (index != M) {
		for (j = 1; j <= N; j++) {
			posit[index] = j;
			if (!isEqual(posit, index+1))
				func(index + 1, posit, N, M);
		}
	}
	else {
		for (j = 0; j < M; j++)
			printf("%d ", posit[j]);
		printf("\n");
		return;
	}
}

// 같으면 1, 아니면 0
int isEqual(int* arr, int M) {
	int i, j;

	for (i = 0; i < M - 1; i++)
		for (j = i + 1; j < M; j++)
			if (arr[i] == arr[j])
				return 1;

	return 0;
}

int main() {

	int i, j, N, M;

	scanf("%d %d", &N, &M);
	int* posit = malloc(sizeof(int) * M);

	for (i = 1; i <= N; i++) {
		posit[0] = i;
		func(1, posit, N, M);
	}

	free(posit);

	return 0;
}
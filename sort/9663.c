//9663

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarr(int* arr[], int N) {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void tozero(int* posit[], int N) {
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			posit[i][j] = 0;
}
int searchcnt(int* posit[], int N) {
	int i, j, result = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			result += posit[i][j];

	return result;
}

int isCanLocate(int* posit[], int* temp[], int x, int y, int N) {
	int i, j, k, l = 1;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			//if this element has value
			if (posit[i][j]) {
				for (k = 0; k < N; k++) {
					temp[i][k] = 1;
					temp[k][j] = 1;
				}

				while (i - l > -1 && j - l > -1) {
					temp[i - l][j - l] = 1;
					l++;
				}
				l = 1;
				while (i - l > -1 && j + l < N) {
					temp[i - l][j + l] = 1;
					l++;
				}
				l = 1;
				while (i + l < N && j - l > -1) {
					temp[i + l][j - l] = 1;
					l++;
				}
				l = 1;
				while (i + l < N && j + l < N) {
					temp[i + l][j + l] = 1;
					l++;
				}
			}
			else
				continue;
		}

	//room is already full
	if (temp[x][y])
		return 0;
	//room is empty
	else
		return 1;
}
void func(int i, int j, int* posit[], int N, int* ans) {
	int index, x=i, y=j;
	int** temp = malloc(sizeof(int*) * N);
	int cal_index = x * N + y;

	for (index = 0; index < N; index++)
		temp[index] = malloc(N * sizeof(int));

	tozero(temp, N);
	printf("\ni:%d j:%d\n", i, j);
	//printf("isCanLocate(posit, temp, i, j, N):%d\n", isCanLocate(posit, temp, i, j, N));
	//printf("%d<%d && searchcnt(posit, N):%d<%d\n", i, N, searchcnt(posit, N), N);

	while (1) {
		if (N == 1) {
			*ans = 1;
			return;
		}

		if (x < N && searchcnt(posit, N) < N) {
			//can locate
			if (isCanLocate(posit, temp, x, y, N)) {
				posit[x][y] = 1;

				if (y != N - 1) {
					y++;
				}
				else {
					x++;
					y = 0;
				}
			}
			//cannot locate
			else {
				if(!(x==i && y==j))
					posit[x][y] = 0;

				if (y != N - 1)
					y++;
				else {
					x++;
					y = 0;
				}
			}
		}
		else {
			if (searchcnt(posit, N) == N) {
				*ans += 1;

				printf("temp :\n");
				printarr(temp, N);
				printf("posit :\n");
				printarr(posit, N);
				printf("*******OK*******\n\n");

				for (index = 0; index < N; index++)
					free(temp[index]);
				free(temp);

				return;
			}
			else {

				printf("temp :\n");
				printarr(temp, N);
				printf("posit :\n");
				printarr(posit, N);
				printf("\n");

				for (index = 0; index < N; index++)
					free(temp[index]);
				free(temp);

				return;
			}
			if (cal_index < N * N); {
				cal_index++;
				func(cal_index / N, cal_index % N, posit, N, &ans);
			}
		}
	}
}

int main() {

	int i, j, N, ans = 0;

	scanf("%d", &N);
	int** posit = malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++)
		posit[i] = malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			tozero(posit, N);
			posit[i][j] = 1;
			func(i, j, posit, N, &ans);
		}

	printf("%d", ans);

	for (i = 0; i < N; i++)
		free(posit[i]);
	free(posit);

	return 0;
}
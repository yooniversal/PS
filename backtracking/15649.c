//15649

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct number {
	char num;
	int value;
};

//value가 1인 index을 보자마자 반환하는 함수
int searchsel(struct number *number, int N, int M) {
	int i;

	//value가 1이면 index 반환
	for (i = 0; i < M; i++)
		if ((number + i)->value)
			return i;
}

void func(int index, int* posit, int i, int N, int M) {
	int j;

	if (index != M) {
		for (j = 1; j < N; j++)
			if (j != i)
				posit[index] = j;

		func(index + 1, posit, i, N, M);
	}
	else {
		for (j = 0; j < M; j++)
			printf("%d ", posit[j]);
		printf("\n");
	}
}

void iprint(int* arr, int N, int M) {
	int i, j;

	for (i = 0; i < M - 1; i++)
		for (j = i + 1; i < M; i++)
			if (arr[i] == arr[j])
				return;

	for (i = 0; i < M; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {

	int i, j, N, M;

	scanf("%d %d", &N, &M);
	int* posit = malloc(sizeof(int) * M); // modifed
	struct number *number = malloc(sizeof(struct number) * M); // unmodifed. check after finishing

	// input each (char)number 0~M & value 1
	// 1 means it gets number related in index
	for (i = 0; i < M; i++) {
		(number + i)->num = '0' + i + 1;
		(number + i)->value = 1;
	}

	for (i = 1; i < N; i++) {
		posit[0] = i;
		func(1, posit, i, N, M);
	}

	/*
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			posit[i] = (number+searchsel(number, N, M))->num; //(number + j)->num;
			(number + searchsel(number, N, M))->value = 0;
		}
	}
	*/


	/*
	//need to input each element of position
	for (i = 0; i < M; i++)
		for (position[i] = 1; position[i] <= N; position[i]++)
			iprint(position, N, M);


	for(position[0]=1; position[0]<=N; position[0]++){
		while (i != M + 1) {
			for (i = 0; i < M; i++)
				iprint(position, N, M);
		}
	}
	position[i] = i+1;
	*/

	free(number);
	free(posit);

	return 0;
}
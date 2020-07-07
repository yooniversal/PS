//1929

#include <stdio.h>
#include <math.h>

int main() {

	int M, N, i, j, cnt = 0;

	scanf("%d %d", &M, &N);
	int* temp = malloc(sizeof(int) * 1000001);

	//initialize
	temp[1] = 0;
	for (i = 2; i <= 1000000; i++)
		temp[i] = 1;

	for (i = 2; i <= sqrt(1000000); i++) {
		if (!temp[i])
			continue;

		for(j=2; i*j<=1000000; j++)
			temp[i*j] = 0;
	}

	for (i = M; i <= N; i++)
		if(temp[i] == 1)
			printf("%d\n", i);

	free(temp);

	return 0;
}
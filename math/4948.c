//4948

#include <stdio.h>
#include <math.h>

int main() {

	int N, i, j, cnt;
	int* temp;

	do {
		scanf("%d", &N);
		temp = (int*)malloc(sizeof(int) * 2 * (N + 1));
		if (!N)
			return 0;
		cnt = 0;

		//initialize
		temp[1] = 0;
		for (i = 2; i <= 2 * N; i++)
			temp[i] = 1;

		for (i = 2; i <= sqrt(2 * N); i++) {
			if (!temp[i])
				continue;

			for (j = 2; i * j <= 2 * N; j++)
				temp[i * j] = 0;
		}

		for (i = N + 1; i <= 2 * N; i++)
			if (temp[i] == 1)
				cnt++;

		printf("%d\n", cnt);
		free(temp);
	} while (N != 0);



	return 0;
}
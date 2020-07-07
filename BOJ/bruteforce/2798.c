//2798

#include <stdio.h>

int main() {

	int N, M, i, j, k, temp = -1, max;
	int* num = malloc(sizeof(int) * 100);

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			for (k = j + 1; k < N; k++) {
				if (num[i] + num[j] + num[k] <= M)
					if(temp == -1)
						temp = num[i] + num[j] + num[k];
					else
						if((M-temp) > (M-(num[i] + num[j] + num[k])))
							temp = num[i] + num[j] + num[k];
			}
		}
	}

	printf("%d", temp);

	free(num);

	return 0;
}
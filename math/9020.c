//9020

#include <stdio.h>
#include <math.h>

struct node {
	int prime1;
	int prime2;
	int diff;
};

int main() {

	int N, i, j, T, keep, cnt = 0, ans1, ans2;
	int* temp = (int*)malloc(sizeof(int) * 1000001);

	scanf("%d", &T);

	//initialize
	temp[1] = 0;

	for (i = 2; i <= 1000000; i++)
		temp[i] = 1;

	for (i = 2; i <= sqrt(1000000); i++) {
		if (!temp[i])
			continue;

		for (j = 2; i * j <= 1000000; j++)
			temp[i * j] = 0;
	}

	while (T != 0) {
		scanf("%d", &N);

		//10
		//answer
		for (i = 2; i <= N; i++) {
			if (temp[i] == 1) {
				j = N - i;

				if (temp[j] == 1) {
					if (j >= i) {
						//initialize first value
						if (cnt == 0) {
							keep = j - i;
							ans1 = i;
							ans2 = j;
							cnt++;
						}
						//search each value that give min diff
						else if (keep > (j - i)) {
							keep = j - i;
							ans1 = i;
							ans2 = j;
						}
					}
				}
			}
		}

		printf("%d %d\n", ans1, ans2);
		cnt = 0;

		T--;
	}
	free(temp);

	return 0;
}
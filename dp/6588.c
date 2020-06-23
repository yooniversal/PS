//6588

#include <stdio.h>
#include <stdlib.h>

//Prime is 0, else is 1
int isNotPrime[1000001];

void goldBach(int N) {
	int i, j, mid = N >> 1;
	for (i = 0, j = N; i <= mid; i++, j--)
		if (i % 2 == 1 && j % 2 == 1 && !isNotPrime[i] && !isNotPrime[j]) {
			printf("%d = %d + %d\n", N, i, j);
			return;
		}
	puts("Goldbach's conjecture is wrong.\n");
}

int main() {

	int N, i, j, keep, cnt = 0, ans1=0, ans2=0;

	//eratosthenes
	for (i = 2; i*i <= 1000000; i++) {
		if (!isNotPrime[i])
			for (j = i*i; j < 1000000; j += i) {
				isNotPrime[j] = 1;
			}
		isNotPrime[1] = 1;
	}

	while (1) {
		scanf("%d", &N);

		if (N == 0) return 0;
		goldBach(N);
	}

	return 0;
}
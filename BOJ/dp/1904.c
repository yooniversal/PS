//1904
#include <stdio.h>

int main() {

	int N, i;
	long long int a, b, sum;
	a = 1;
	b = 2;

	scanf("%d", &N);

	if (N == 1) sum = a;
	else if (N == 2) sum = b;
	else if (N > 2) {
		for (i = 2; i < N; i++) {
			sum = (a + b) % 15746;
			a = b;
			b = sum;
		}
	}
	printf("%lld", sum);

	return 0;
}
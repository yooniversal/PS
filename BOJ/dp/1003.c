//1003
#include <stdio.h>

long long int value_table0[41] = { 1, 0, 1 };
long long int value_table1[41] = { 0, 1, 1 };

long long int pibo_0(int N) {

	if (N == 0) return 1;
	else if (N == 1) return 0;
	else if (N == 2) return 1;
	if (value_table0[N]) {
		return value_table0[N];
	}
	else {
		value_table0[N] = pibo_0(N - 1) + pibo_0(N - 2);	
		return pibo_0(N - 1) + pibo_0(N - 2);
	}
}

long long int pibo_1(int N) {

	if (N == 0) return 0;
	else if (N == 1) return 1;
	if (value_table1[N]) {
		return value_table1[N];
	}
	else {
		value_table1[N] = pibo_1(N - 1) + pibo_1(N - 2);
		return pibo_1(N - 1) + pibo_1(N - 2);
	}
}

int main() {

	int N, T;

	scanf("%d", &T);

	while (T != 0) {

		scanf("%d", &N);

		printf("%lld %lld\n", pibo_0(N), pibo_1(N));

		T--;
	}

	return 0;
}
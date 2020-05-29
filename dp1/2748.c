#include <stdio.h>

//경험적 정보(Heuristic info)
long long int value_table[91] = { 0, 1, 1 };

long long int dynamic_pibo(int N) {

	long long int temp1, temp2;

	if (N <= 0) return 0;

	//When have pibo(N) in value_table, return from value_table
	if (value_table[N]) return value_table[N];
	else {
		temp1 = dynamic_pibo(N - 1);
		temp2 = dynamic_pibo(N - 2);
		value_table[N] = temp1 + temp2;
		return temp1 + temp2;
	}
}

int main() {

	int N;
	
		scanf("%d", &N);

		printf("%lld", dynamic_pibo(N));

	return 0;
}
//9095

#include <stdio.h>

int value_table[91] = { 0, 1, 2, 4 };

int dynamic_pibo(int N) {

	int temp1, temp2, temp3;

	if (N <= 0) return 0;

	//When have pibo(N) in value_table, return from value_table
	if (value_table[N]) return value_table[N];
	else {
		temp1 = dynamic_pibo(N - 1);
		temp2 = dynamic_pibo(N - 2);
		temp3 = dynamic_pibo(N - 3);
		value_table[N] = temp1 + temp2 + temp3;
		return temp1 + temp2 + temp3;
	}
}

int main() {

	int N, T;

	scanf("%d", &T);

	while (T != 0) {
		scanf("%d", &N);

		printf("%d\n", dynamic_pibo(N));
		T--;
	}

	return 0;
}
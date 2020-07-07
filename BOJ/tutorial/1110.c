//1110

#include <stdio.h>

int main() {

	int n, temp1, temp2, keep, cnt=0;

	scanf("%d", &n);

	keep = n;
	do{
		temp1 = n / 10 + n % 10;
		temp2 = n % 10 * 10 + temp1 % 10;
		n = temp2;

		cnt++;
	} while (n != keep);

	printf("%d", cnt);

	return 0;
}
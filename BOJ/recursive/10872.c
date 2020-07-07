//10872

#include <stdio.h>

int pactorial(int n){
	if (n != 0)
		return n * pactorial(n - 1);
	else
		return 1;
}

int main() {

	int n;

	scanf("%d", &n);

	printf("%d", pactorial(n));

	return 0;
}
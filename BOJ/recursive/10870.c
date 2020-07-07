//10870

#include <stdio.h>

int pibo(int n){
	if (n >= 2)
		return pibo(n - 1) + pibo(n - 2);
	else if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
}

int main() {

	int n;

	scanf("%d", &n);

	printf("%d", pibo(n));

	return 0;
}
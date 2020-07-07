//11050

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


int pac(int a) {

	int ans = 1;

	for (int i = 1; i <= a; i++)
		ans *= i;

	return ans;
}

int combi(int n, int r) {

	return pac(n) / (pac(n - r) * pac(r));
}

int main() {

	int n, r;
	
	scanf("%d", &n);
	scanf("%d", &r);

	printf("%d", combi(n, r));

	return 0;
}
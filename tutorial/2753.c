//2753

#include <stdio.h>
int main() {

	int a;

	scanf("%d", &a);

	if (!(a % 100))
		if (!(a % 400))
			printf("1");
		else
			printf("0");
	else if (!(a % 4)) printf("1");
	else printf("0");

	return 0;
}
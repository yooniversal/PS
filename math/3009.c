//3009

#include <stdio.h>

int diff(int a, int b, int c);
int main() {

	int x[3], y[3], a, b;

	scanf("%d %d", &x[0], &y[0]);
	scanf("%d %d", &x[1], &y[1]);
	scanf("%d %d", &x[2], &y[2]);

	a = diff(x[0], x[1], x[2]);
	b = diff(y[0], y[1], y[2]);

	printf("%d %d", a, b);

	return 0;
}

int diff(int a, int b, int c) {
	if (a == b) return c;
	else if (a == c) return b;
	else return a;
}
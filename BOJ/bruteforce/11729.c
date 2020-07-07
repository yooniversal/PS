//11729

#include <stdio.h>

int ans(int n) {
	int i, temp=1;

	for (i = 0; i < n; i++)
		temp *= 2;

	return temp;
}
void hanoi(char start, char temp, char end, int n){

	if (n == 1) {
		printf("%c %c\n", start, end);	
	}
	else{
		hanoi(start, end, temp, n-1);
		printf("%c %c\n", start, end);
		hanoi(temp, start, end, n-1);
	}
}

int main() {

	int n;

	scanf("%d", &n);

	printf("%d\n", ans(n)-1);
	hanoi('1', '2', '3', n);

	return 0;
}
//13866
#include <stdio.h>

int abs(int n) {
	if (n >= 0) return n;
	else return n * (-1);
}
int main() {

	int arr[4], i, result;

	for(i=0; i<4; i++)
		scanf("%d", &arr[i]);

	result = arr[0] + arr[3] - (arr[1] + arr[2]);

	printf("%d", abs(result));

	return 0;
}
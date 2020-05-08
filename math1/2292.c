// 2292

#include <stdio.h>

int an(int n);
int main() {

	int input, n=1;
	int temp = 0;

	scanf("%d", &input);

	while(n <= 1000000000) {
		if (input <= an(n)) {
			temp = n;
			break;
		}
		else if (input == an(n)) {
			temp = n;
			break;
		}
		n++;
	}

	printf("%d", temp);

	return 0;


}

int an(int n) {
	return 3 * n * n - 3 * n + 1;
}
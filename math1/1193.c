// 1193
#include <stdio.h>

int an(int n);
int main() {

	int X, n, row, col;

	scanf("%d", &X);

	for (n = 1; n <= 10000000; n++) {
		if (an(n) > X) {
			if ((n-1) % 2 == 1) { // È¦¼ö
				if (X % (n-1) != 0)
					col = X % (n-1);
				else
					col = n-1;
				row = n - col;
			}
			else { // Â¦¼ö
				if ((n-1) == 2) {
					if (X == 2) row = 1;
					else row = 2;
				}
				else
					row = X % (an(n-1) - 1);
				col = n - row;
			}
			
			printf("%d/%d", row, col);
			return 0;
				
		}
		else if (an(n) == X) {
			if (n % 2 == 1) { // È¦¼ö
				if (X % n != 0)
					col = X % n;
				else
					col = n;
				row = (n+1) - col;
			}
			else { // Â¦¼ö
				if (n == 2) {
					if (X == 2) row = 1;
					else row = 2;
				}
				else
					row = X % (an(n) - 1);
				col = (n+1) - row;
			}

			printf("%d/%d", row, col);
			return 0;
		}
	}

	return 0;
}

int an(int n) {
	return (n * n - n + 2) / 2;
}
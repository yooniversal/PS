//10250

#include <stdio.h>
int main() {

	int H, W, N, T;
	int Y, X;
	
	scanf("%d", &T);
	while (T != 0) {
		scanf("%d %d %d", &H, &W, &N);

		if (N % H == 0) {
			Y = H;
			X = N / H;
		}
		else {
			Y = N % H;
			X = N / H + 1;
		}
		
		printf("%d%02d\n", Y,X);

		T--;
	}
}
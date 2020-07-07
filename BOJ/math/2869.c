// 2869

#include <stdio.h>
int main() {

	int present = 0, height, A, B;
	int days = 0, temp;

	scanf("%d %d %d", &A, &B, &height);

	temp = (height - B - 1) / (A - B);
	days += temp;
	days++;

	printf("%d", days);
	
	// 시간 초과
	/*
	while (present <= height) {
		if (present < height) {
			present += A; // 2

			days++;

			if (present >= height) {
				printf("%d", days); // 4
				return 0;
			}

			present -= B;	
		}
	}
	*/

	return 0;
}
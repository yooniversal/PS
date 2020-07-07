//2447

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//각 위치에 따라 어떤 문자가 적절한지 판별 후 출력
void makestar(int x, int y, int num) {

	if ((x/num) % 3 == 1 && (y/num) % 3 == 1)
		printf(" ");
	else {
		if (num / 3 == 0)
			printf("*");
		else
			//num은 작아질 수록 공백을 출력하는 위치 간격이 넓어진다
			makestar(x, y, num / 3);
	}
}

int main() {
	int num;

	scanf("%d", &num);

	//각 위치를 대입
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			makestar(i, j, num);
		printf("\n");
	}

	return 0;
}
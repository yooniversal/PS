//2447

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//�� ��ġ�� ���� � ���ڰ� �������� �Ǻ� �� ���
void makestar(int x, int y, int num) {

	if ((x/num) % 3 == 1 && (y/num) % 3 == 1)
		printf(" ");
	else {
		if (num / 3 == 0)
			printf("*");
		else
			//num�� �۾��� ���� ������ ����ϴ� ��ġ ������ �о�����
			makestar(x, y, num / 3);
	}
}

int main() {
	int num;

	scanf("%d", &num);

	//�� ��ġ�� ����
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			makestar(i, j, num);
		printf("\n");
	}

	return 0;
}
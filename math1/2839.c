// 2839

#include <stdio.h>

int main() {

	int q5, q3, input;
	int result;

	scanf("%d", &input);

	result = -1;	// for�� ���� if���� �ɸ��� �ʴ´ٸ� -1�� ���

	for (q5 = 0; q5 * 5 <= input; q5++)					// 5�� ������ ��� Case
		for (q3 = 0; q5 * 5 + q3 * 3 <= input; q3++)	// 5�׸��� 3���� ������ ��� Case
			if (q5 * 5 + q3 * 3 == input)				// �̷��� ���� ���� ���������� input�� ���ٸ�
				result = q5 + q3;						// result�� ����

	printf("%d", result);
}
// 2839

#include <stdio.h>

int main() {

	int q5, q3, input;
	int result;

	scanf("%d", &input);

	result = -1;	// for문 안의 if문에 걸리지 않는다면 -1을 출력

	for (q5 = 0; q5 * 5 <= input; q5++)					// 5로 나누는 모든 Case
		for (q3 = 0; q5 * 5 + q3 * 3 <= input; q3++)	// 5그리고 3으로 나누는 모든 Case
			if (q5 * 5 + q3 * 3 == input)				// 이렇게 나눈 값이 최종적으로 input과 같다면
				result = q5 + q3;						// result에 대입

	printf("%d", result);
}
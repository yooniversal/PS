// 1712¹ø

#include <stdio.h>
int solution(int a, int b, int c)
{
	if (b == c)
		return -1;
	int result = a / (c - b) + 1;
	if (result > 0)
		return result;
	else
		return -1;
}

int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	int result = solution(a, b, c);
	printf("%d\n", result);

	return 0;
}
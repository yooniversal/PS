//11022

#include <stdio.h>
int main() {

	int T, a, b, cnt = 1;

	scanf("%d", &T);

	while (T != 0) {

		scanf("%d %d", &a, &b);

		printf("Case #%d: %d + %d = %d\n", cnt,a,b, a + b);

		cnt++;

		T--;
	}

	return 0;
}
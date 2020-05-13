//11654

#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, input, ans=0, i;

	scanf("%d", &T);
	getchar();

	for(i=0; i<T; T--)
		ans += getchar() - '0';

	printf("%d", ans);

	return 0;
}
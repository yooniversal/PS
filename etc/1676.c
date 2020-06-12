//1676

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int n, temp, ans = 1, cnt = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		ans *= i;
		if (ans % 10 == 0) {
			while (ans % 10 == 0) {
				ans /= 10;
				cnt++;
			}
		}
		else if (ans > 10000)
			ans %= 10000;
	}

	printf("%d", cnt);

	return 0;
}
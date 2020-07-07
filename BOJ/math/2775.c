//2775

#include <stdio.h>
int func(int k, int n);
int main() {

	int T, k, n;

	scanf("%d", &T);

	while (T != 0) {

		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", func(k, n));

		T--;
	}
}

int func(int k, int n) {
	int i=1;
	int result = 0;

	if (k > 0)
		while (i != n+1) {
			result += func(k - 1, i);
			i++;
		}
	if (k == 0)
		return n;

	return result;
}
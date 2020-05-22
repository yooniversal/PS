//10989

#include <stdio.h>

int main() {
	int T, i, temp;
	int a[10001] = { 0 };

	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		scanf("%d", &temp);
		a[temp]++;
	}

	for (i = 1; i <= 10000; i++) {
		while(a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		}
	}

	return 0;
}
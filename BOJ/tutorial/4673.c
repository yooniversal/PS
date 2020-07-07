//4673

#include <stdio.h>
#include <stdlib.h>

int fun_a(int n);
int main() {
	int i, add;
	int* arr = malloc(sizeof(int)*10001);

	for (i = 1; i <= 10000; i++)
		*(arr+i) = i;

	for (i = 1; i <= 10000; i++) {
		add = 0;
		add = i + fun_a(i);
		if (add <= 10000)
			*(arr + add) = 0;
		if (*(arr + i) != 0)
			printf("%d\n", *(arr + i));
	}

	free(arr);

	return 0;
}

int fun_a(int n) {
	int ans = 0;

	while (n != 0) {
		ans += n % 10;
		n /= 10;
	}
	
	return ans;
}
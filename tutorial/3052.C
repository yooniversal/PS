//3052

#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, arr[10], cnt=1, temp;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		arr[i] = arr[i] % 42;
	}

	for (j = 0; j < 9; j++) {
		for (i = j + 1; i < 10; i++) {
			if (arr[i] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (i = 0; i < 9; i++)
		if (arr[i] != arr[i + 1])
			cnt++;

	printf("%d", cnt);

	return 0;
}
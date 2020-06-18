//4153

#include <stdio.h>

void sort(int* a) {
	int max, max_index=0, i, temp;

	max = a[0];
	for(i=0; i<3; i++)
		if (max < a[i]) {
			max = a[i];
			max_index = i;
		}

	temp = a[max_index];
	a[max_index] = a[0];
	a[0] = temp;
}
int main() {

	int arr[3];

	while (1) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			return 0;

		sort(arr);

		if (arr[1] * arr[1] + arr[2] * arr[2] == arr[0] * arr[0])
			printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}
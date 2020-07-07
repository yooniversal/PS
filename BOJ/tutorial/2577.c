//2577

#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b, c, i, j, cnt[10] = { 0 };
	char temp;
	char arr[10];

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	sprintf(arr, "%d", a*b*c);

	for(i = 0; i < 10; i++) {
		temp = '0'+i;
		for (j = 0; j < 10; j++) {
			if(arr[j] == temp)
				cnt[i]++;
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d\n", cnt[i]);

	return 0;
}
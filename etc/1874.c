//1874

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100001];
char out[200001];

int main() {
	int n, i, j, temp=0, num, count=0, arrtop=0, outtop=0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {

		scanf("%d", &num);

		if (num > n || num <= 0) {
			printf("NO");
			return 0;
		}

		if (count < num) {
			for (j = count; j < num; j++) {
				a[arrtop++] = ++count;
				out[outtop++] = '+';
			}
		}

		if (num == a[arrtop - 1]) {
			a[--arrtop] = 0;
			out[outtop++] = '-';
		}
		else {
			printf("NO");
			return 0;
		}
	}

	for (i = 0; i < outtop; i++)
		printf("%c\n", out[i]);

	return 0;
}
//9012

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, j, cnt=0;
	char arr[51];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", arr);

		for (j = 0; j < strlen(arr); j++) {
			if (arr[j] == '(') cnt++;
			else cnt--;

			if (cnt < 0) break;
		}

		if (cnt == 0) printf("YES\n");
		else printf("NO\n");

		cnt = 0;
	}


	return 0;
}
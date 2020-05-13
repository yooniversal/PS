//2675

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char S[20];
	int i, j, R, T;

	scanf("%d", &T);

	while (T != 0) {

		scanf("%d", &R);
		scanf("%s", &S);

		for (i = 0; i < strlen(S); i++)
			for(j=0; j<R; j++)
				printf("%c", S[i]);

		printf("\n");

		T--;
	}

	return 0;
}
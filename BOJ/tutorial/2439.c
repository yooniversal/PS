//2439

#include <stdio.h>

int main(){

	int N, X, AN, i;

	scanf("%d %d", &N, &X);

	for (i = 0; i < N; i++) {
		scanf("%d", &AN);
		if (AN < X) printf("%d ", AN);
	}

	return 0;
}	
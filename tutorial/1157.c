//1157

단, 대문자와 소문자를 구분하지 않는다.
단, 대문자와 소문자를 구분하지 않는다.
단, 대문자와 소문자를 구분하지 않는다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* a);
int main() {
	char* S = malloc(sizeof(char) * 1000000);
	int i, temp[52] = { 0 }, max;

	scanf("%s", S);

	for (i = 0; i < 1000000; i++) {
		if(*(S+i)<'a')
			temp[*(S + i) - 'A']++;
		else
			temp[*(S + i) - 'A' - 6]++;
	}
	
	max = temp[0];
	for (i = 0; i < 52; i++)
		if (temp[i] > max)
			max = i+1;

	printf("%d %d\n", max, temp[max-1]);

	for (i = 0; i < 52; i++)
		printf("%d ", temp[i]);
	printf("\n");

	sort(&temp);

	for (i = 0; i < 52; i++)
		printf("%d ", temp[i]);
	
	if (temp[0] == temp[1]) printf("?");
	else {
		if(max<26)
			printf("\n%c", 'A' + max);
		else
			printf("\n%c", max + 'A' + 6);
	}

	free(S);

	return 0;
}

void sort(int* a){
	int i, j, temp;

	for (j = 0; j < 51; j++) {
		for (i = 0; i < 51 - j; i++)
			if (a[i] < a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
	}	
}
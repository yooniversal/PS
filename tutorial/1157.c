//1157

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* a);
int main() {
	char* S = malloc(sizeof(char) * 1000001);
	int i, temp[26] = { 0 }, max=0;
	int maxvalue = 0;

	scanf("%s", S);

	for (i = 0; i < 1000001; i++) {
		if(*(S + i) >= 'A' && *(S+i)<='Z') //uppercase
			temp[*(S + i) - 'A']++;
		else if(*(S + i) >= 'a' && *(S + i) <= 'z')//lowercase
			temp[*(S + i) - 'A' - 32]++;
	}
	
	max = temp[0];
	for (i = 0; i < 26; i++) {
		if (temp[i] > maxvalue) {
			maxvalue = temp[i];
			max = i+1;
		}
	}
	
	/*
	//print max, temp[max-1]
	printf("%d %d %d\n", max, temp[max-1], maxvalue);

	//print not sorted temp[]
	for (i = 0; i < 26; i++)
		printf("%d ", temp[i]);
	printf("\n");
	*/
	

	sort(temp);
	
	/*
	for (i = 0; i < 26; i++)
		printf("%d ", temp[i]);
	*/
	
	
	if (temp[0] == temp[1]) printf("?");
	else
			printf("%c", 'A' + max-1);


	free(S);

	return 0;
}

void sort(int* a){
	int i, j, temp;

	for (j = 0; j < 25; j++) {
		for (i = 0; i < 25 - j; i++)
			if (a[i] < a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
	}	
}
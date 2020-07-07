//8958

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int T, i=0, point=0, result=0;
	char arr[81];

	scanf("%d", &T);

	while (T != 0) {
		point = 0;
		result = 0;
		for (i = 0; strlen(arr); i++)
			arr[i] = 0;

		scanf("%s", arr);

		//search each char in arr
		for(i=0; i<strlen(arr); i++){
			if (arr[i] == 'O') {
				point++;
				result += point;
			}
			if (arr[i] == 'X')
				point = 0;
		}	

		printf("%d\n", result);
		T--;
	}

	return 0;
}
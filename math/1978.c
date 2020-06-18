//1978

#include <stdio.h>

int isnumber(int num);
int main() {

	int T, input, cnt=0;

	scanf("%d", &T);

	while (T != 0) {
		scanf("%d", &input);

		if (isnumber(input)) cnt++;

		T--;
	}

	printf("%d", cnt);

	return 0;
}

int isnumber(int num) {
	int i, cnt=0;
	
	for (i = 1; i <= num; i++)
		if ((num % i) == 0) cnt++;

	if (cnt == 2) return 1;
	else return 0;
}
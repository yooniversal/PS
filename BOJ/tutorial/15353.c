//15353

#include <stdio.h>
#include <string.h>

char input1[1000002];
char input2[1000002];
int m[1000002] = { 0, }, n[1000002] = { 0, }, s[1000002] = { 0, };

int main() {
	
	int carry, i, ml, nl, max, temp;

	scanf("%s", input1);
	scanf("%s", input2);

	ml = strlen(input1);
	nl = strlen(input2);

	for (i = 0; i < ml; i++)
		m[ml - i - 1] = input1[i] - '0';

	for (i = 0; i < nl; i++)
		n[nl - i - 1] = input2[i] - '0';

	max = ml;
	if (ml < nl) max = nl;

	carry = 0;
	for (i = 0; i < max; i++) {
		temp = m[i] + n[i] + carry;
		carry = temp / 10;
		s[i] = temp % 10;
	}

	if (carry > 0) {
		s[max] = carry;
		max++;
	}

	for (i = 0; i < max; i++)
		printf("%d", s[max - i - 1]);

	return 0;
	
}
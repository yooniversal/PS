//1009

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	
	int T, a, b;
	int num[10][4] = {
		{10,10,10,10},
		{1, 1,1,1},
		{6,2,4,8},
		{1,3,9,7},
		{6,4,6,4},
		{5,5,5,5},
		{6,6,6,6},
		{1,7,9,3},
		{6,8,4,2},
		{1,9,1,9}
	};

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &a, &b);

		if (a >= 10) a %= 10;
		if (b >= 4) b %= 4;
		
		printf("%d\n", num[a][b]);
 	}

	return 0;
}
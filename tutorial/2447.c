//2447

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[6561][6561];
int power(int a, int n) {
	int i, ans = 1;
	
	if (n == 0) return 1;
	else {
		for (i = 0; i < n; i++)
			ans *= a;
	}
}

void makestar(int n) {
	int i, j, subn=0, temp, cnt=0;

	temp = n;

	while (temp != 0) {
		temp /= 3;
		subn++;
	}
	/*
	for (j = 1; j < n; j += 3) {
		for (i = 1; i < n; i += 3) {
			arr[j][i] = 1;
		}
	}
	*/

	for (j = (n / 3)/3; j < ((n / 3)/3) * 2; j++) {
		for (i = (n / 3)/3; i < ((n / 3)/3) * 2; i++) {
			arr[j][i] = 1;
		}
	}

	/*
	//sub mid box
	for (j = power(3,0); j <= power(3,subn); j++) {
		for (i = power(3,cnt); i < n; i+= power(3,cnt+1)) {
			cnt = j/3;
			arr[j][i] = 1;
		}
		cnt++;
	}
	*/

	//big mid box
	for (j = n/3; j < (n/3)*2; j++) {
		for (i = n/3; i < (n / 3) * 2; i++) {
			arr[j][i] = 1;
		}
	}
}



int main() {
	int n, i, j;

	scanf("%d", &n);

	makestar(n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (arr[i][j] == 1) printf(" ");
			else printf("*");
		printf("\n");
	}

	return 0;
}
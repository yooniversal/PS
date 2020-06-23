//2565
//greedy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[501] = { 0, };
int maxind;

int checkdpzero(){
	int i;

	for (i = 0; i < maxind; i++)
		if (dp[i] != 0)
			return 0;

	return 1;
}

void getvalue(int* arr, int n) {
	int i;

	for (i = 1; i <= n; i++)
		if (arr[i] > arr[n])
			if (arr[i] != 0)
				dp[n]++;
	
	for (i = n; i <= maxind; i++)
		if (arr[i] < arr[n])
			if (arr[i] != 0)
				dp[n]++;
}

int maxindex(int* arr) {
	int i, index, max;

	max = arr[1];
	index = 1;
	for (i = 1; i <= maxind; i++)
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}

	return index;
}

int main() {
	int n, i, cnt = 0, a, b;
	int arr[501] = { 0, };

	scanf("%d", &n);

	maxind = 0;

	//input
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		arr[a] = b;
		if (maxind < a)
			maxind = a;
	}

	dp[0] = 0;

	//input dp array
	for (i = 1; i <= maxind; i++)
		if(arr[i] != 0)
			getvalue(arr, i);

	while (checkdpzero() == 0) {
		arr[maxindex(dp)] = 0;

		memset(dp, 0, sizeof(dp));


		//update dp array
		for (i = 1; i <= maxind; i++)
			if(arr[i] != 0)
				getvalue(arr, i);

		cnt++;
	}

	printf("%d", cnt);

	return 0;
}
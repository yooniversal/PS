//14002

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1001] = { 0, };
int a[1001] = { 0, };
int route[1001] = { 0, };

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int maxindex(int* arr) {
	int i, index, max;

	max = arr[0];
	index = 0;
	for (i = 0; i <= leng(arr); i++)
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}

	return index;
}
int leng(int* arr) {
	int i;

	for (i = 1; i < 1001; i++)
		if (arr[i] == 0)
			return i - 1;

	return i - 1;
}

int searchindex(int key) {
	int i;
	int n = leng(a);

	for (i = 1; i < n; i++)
		if (a[i - 1] < key && key <= a[i])
			return i;

	return n;
}

//modifed dp[i] from equal scope with leng(a) to all of arr[i]
//after modifying, each of arr[i] getting dp[i] related with order number
int dpfunc(int* arr, int n) {
	int i, j;

	if (dp[1] == 0) {
		dp[1] = 1;
		a[1] = arr[1];
		return a[1];
	}
	else {
		if (searchindex(arr[n]) <= leng(dp) && a[searchindex(arr[n])] >= arr[n]) {
			dp[n] = searchindex(arr[n]);
			a[searchindex(arr[n])] = arr[n];

		}
		else {
			dp[n] = searchindex(arr[n]) + 1;
			a[searchindex(arr[n]) + 1] = arr[n];
		}
	}
}

//return value matched in order number
int searchvalue(int* arr, int *n, int keynum) {
	int i;

	for (i = *n; i >= 1; i--) {
		if (dp[i] == keynum) {
			*n = i-1;
			return arr[i];
		}
	}
}

int main() {
	int n, i, cnt;

	scanf("%d", &n);
	int arr[1001] = { 0, };

	//input
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0;
	a[0] = 0;

	for (i = 1; i <= n; i++)
		dpfunc(arr, i);

	cnt = leng(a);
	i = n;
	while(cnt!=0){
		route[cnt] = searchvalue(arr, &i, cnt);
		cnt--;
	}

	printf("%d\n", leng(a));

	for (i = 1; i <= leng(a); i++)
		printf("%d ",route[i]);

	return 0;
}
//12015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1000001] = { 0, };
int a[1000001] = { 0, };
int temp[1000001] = { 0, };

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

	for (i = 1; i < 1000001; i++)
		if (arr[i] == 0)
			return i - 1;

	return i - 1;
}

//BinarySearch를 통해 문제를 해결할 수 있다
//이 방법은 O(n^2)로, 문제를 해결할 수 없는 방법을 택하고 있음
//dpfunc에서 for문 안에 searchindex가 돌고있는데 이 함수 또한 루프를 돌고 있음
//이진탐색이 아니고 이분탐색
int searchindex(int* arr, int key, int start, int end) {
	int i;
	int mid = (start+end)/2;

	if (arr[mid+1]==NULL) return mid;
	
	while (end - start > 0) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < key && key <= arr[mid]) return mid;
		else if (arr[mid] >= key) end = mid - 1;
		else start = mid + 1;
	}
	return end;

	/*
	for (i = 1; i < n; i++)
		if (a[i - 1] < key && key <= a[i])
			return i;
	

	return n;
	*/
}

/*
int dpfunc(int* arr, int n) {
	int i, j;

	if (dp[1] == 0) {
		dp[1] = 1;
		a[1] = arr[1];
		return a[1];
	}
	else {
		if (searchindex(arr[n], 1, leng(a)) <= leng(dp) && a[searchindex(arr[n], 1, leng(a))] >= arr[n])
			a[searchindex(arr[n], 1, leng(a))] = arr[n];
		else {
			dp[searchindex(arr[n], 1, leng(a)) + 1] = searchindex(arr[n], 1, leng(a)) + 1;
			a[searchindex(arr[n], 1, leng(a)) + 1] = arr[n];
		}
	}
}
*/

int main() {
	int n, i, cnt=1, tempvalue;

	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * 1000001);

	//input
	//for (i = 1; i <= n; i++)
	//	scanf("%d", &arr[i]);
	scanf("%d", &arr[1]);

	dp[0] = 0;
	a[0] = 0;
	arr[0] = 0;

	
	//for (i = 1; i <= n; i++)
	//	dpfunc(arr, i);

	
	//for (i = 1; i <= maxindex(dp); i++)
	//	printf("a[%d]=%d dp[%d]=%d\n",i, a[i], i, dp[i]);
	
	for (i = 2; i <= n; i++) {
		scanf("%d", &tempvalue);
		if (arr[cnt] < tempvalue) {
			arr[++cnt] = tempvalue;
		}
		else{
			arr[searchindex(arr, tempvalue, 1, cnt)] = tempvalue;
		}
	}
	

	//for (i = 1; i <= cnt; i++)
	//	printf("arr[%d]=%d\n", i, arr[i]);

	printf("%d", cnt);
	//printf("%d", maxindex(dp));

	free(arr);

	return 0;
}
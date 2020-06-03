//2565
//lis (use ascending order)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[501] = { 0, };
int a[501] = { 0, };
int maxind = 0;
int route[501];

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 501);
	int k;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[index] = arr[i];
			i++;
		}
		else {
			sorted[index] = arr[j];
			j++;
		}
		index++;
	}

	if (i > mid)
		for (k = j; k <= end; k++) {
			sorted[index] = arr[k];
			index++;
		}
	else
		for (k = i; k <= mid; k++) {
			sorted[index] = arr[k];
			index++;
		}

	//copy to arr
	for (k = start; k <= end; k++)
		arr[k] = sorted[k];

	free(sorted);
}

void mergesort(int* arr, int p, int q) {
	int n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

int leng(int* arr) {
	int i;

	for (i = 1; i < 501; i++)
		if (arr[i] == 0)
			return i - 1;

	return i - 1;
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

int searchindex(int key) {
	int i;
	int n = leng(a);

	for (i = 1; i < n; i++)
		if (a[i - 1] < key && key <= a[i])
			return i;

	return n;
}

int dpfunc(int* arr, int n) {
	int i;

	if (dp[1] == 0) {
		dp[1] = 1;
		a[1] = arr[1];
		route[1] = arr[1];
		return a[1];
	}
	else {
		//update value in used index
		if (searchindex(arr[n]) <= leng(dp) && a[searchindex(arr[n])] >= arr[n]) {
			a[searchindex(arr[n])] = arr[n];
		}
		//update value in new index
		else {
			dp[searchindex(arr[n]) + 1] = searchindex(arr[n]) + 1;
			a[searchindex(arr[n]) + 1] = arr[n];
			
			//update new long route (1st -> end index(leng(route)+1))
			for (i = 1; i <= n; i++)
				route[i] = a[i];
			route[leng(route)+1] = arr[n];
			
		}
	}
}

int main() {
	int n, i, j, temp1, temp2, cnt, min, max, ans=0;

	scanf("%d", &n);
	int arr[501] = { 0, };
	int valueblank[501];
	int temparr[501];
	valueblank[0] = temparr[0] = 0;

	
	//input
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &temp1, &temp2);
		arr[temp1] = temp2;

		valueblank[i] = temp2;

		if (maxind < temp1)
			maxind = temp1;
	}
	
	mergesort(valueblank, 1, n);
	
	
	//sort index(diff 1) in temparr
	cnt = 1;
	for (i = 1; i <= maxind; i++)
		if (arr[i] != 0) {
			temparr[cnt] = arr[i];
			cnt++;
		}
	
	/*
	//sort value(diff 1) in temparr
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			if (temparr[i] == valueblank[j])
				temparr[i] = j;
	}
	*/

	dp[0] = 0;
	a[0] = 0;
	route[0] = 0;
	
	//arr -> temparr
	for (i = 1; i <= n; i++)
		dpfunc(temparr, i);
	
	/*
	for (i = 1; i <= n; i++)
		printf("temparr[%d] = %d\n", i, temparr[i]);
	
	for (i = 1; i <= maxindex(dp); i++)
		printf("route[%d] = %d\n", i, route[i]);

	printf("maxindex(dp) : %d\n", maxindex(dp));
	
	min = route[1];
	max = route[maxindex(dp)];

	for (i = 1; i <= n; i++)
		if (temparr[i] == min) {
			min = i;
			break;
		}

	for(i=1; i<=n; i++)
		if (temparr[i] == max) {
			max = i;
			break;
		}

	for (i = min; i <= max; i++) {
		for (j = 1; j <= maxindex(dp); j++) {
			if (temparr[i] == route[j]) break;
			if (j == maxindex(dp)) ans++;
		}
	}
	
	
	printf("ans = %d", ans);
	*/

	//free(temparr);
	//free(valueblank);

	printf("%d", n - maxindex(dp));

	return 0;
}
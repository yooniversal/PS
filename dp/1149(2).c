//1149

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value_table[1001][3];
int ind0 = -1;
int ind1 = -1;
int ind2 = -1;

int dp(int a, int b, int c) {
	int i, min, arr[3];

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	min = arr[0];

	for (i = 0; i < 3; i++) {
		if (min > arr[i])
			min = arr[i];
	}

	return min;
}

int min(int arr[][3], int N, int start) {
	int i, temp, min;

	if (start == 0) {

		//initialize
		if (ind0 == -1) {
			min = arr[N][0];
			ind0 = start;

		}
		else if (ind0 != 0 && ind0 != -1) {
			temp = ind0;
			min = arr[N][0];

			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind0 = i;
				}
			}
		}
		else {
			temp = ind0;
			min = arr[N][1];

			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind0 = i;
				}
			}
		}
	}
	else if (start == 1) {

		//initialize
		if (ind1 == -1) {
			min = arr[N][1];
			ind1 = start;

		}
		else if (ind1 != 0) {
			temp = ind1;
			min = arr[N][0];
			//printf("****bef -- ind1 = %d\n", ind1);
			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind1 = i;
				}
				//printf("****aft -- ind1 = %d\n", ind1);
			}
		}
		else {
			temp = ind1;
			min = arr[N][1];

			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind1 = i;
				}
			}
		}
	}
	else {

		//initialize
		if (ind2 == -1) {
			min = arr[N][2];
			ind2 = start;

		}
		else if (ind2 != 0) {
			temp = ind2;
			min = arr[N][0];

			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind2 = i;
				}
			}
		}
		else {
			temp = ind2;
			min = arr[N][1];

			for (i = 0; i < 3; i++) {
				if (temp == i)
					continue;
				else if (min >= arr[N][i]) {
					min = arr[N][i];
					ind2 = i;
				}
			}
		}
	}

	return min;
}

int dp0(int N, int arr[][3]) {

	int i;

	if (N == 1) {
		for (i = 0; i < 3; i++)
			value_table[1][i] = arr[1][i];

		return min(arr, 1, 0);
	}
	else if (value_table[N][0]) return value_table[N][0];
	else {
		value_table[N][0] = dp0(N - 1, arr) + min(arr, N, 0);
		return value_table[N][0];
	}
}

int dp1(int N, int arr[][3]) {

	int i;

	if (N == 1) {
		for (i = 0; i < 3; i++)
			value_table[1][i] = arr[1][i];

		return min(arr, 1, 1);
	}
	else if (value_table[N][1]) return value_table[N][1];
	else {
		value_table[N][1] = dp1(N - 1, arr) + min(arr, N, 1);
		return value_table[N][1];
	}
}

int dp2(int N, int arr[][3]) {

	int i;

	if (N == 1) {
		for (i = 0; i < 3; i++)
			value_table[1][i] = arr[1][i];

		return min(arr, 1, 2);
	}
	else if (value_table[N][2]) return value_table[N][2];
	else {
		value_table[N][2] = dp2(N - 1, arr) + min(arr, N, 2);
		return value_table[N][2];
	}
}

int main() {

	int N, arr[1001][3], i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);

	printf("%d\n", dp(dp0(N, arr), dp1(N, arr), dp2(N, arr)));

	//printf("ind0 = %d ind1 = %d ind2 = %d\n", ind0, ind1, ind2);

	for (i = 1; i <= N; i++)
		for (int j = 0; j <= 2; j++)
			printf("value[%d][%d] = %d\n", i, j, value_table[i][j]);


	return 0;
}
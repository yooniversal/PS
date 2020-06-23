//11054

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int dp[1001] = { 0, };
int dp2[1001] = { 0, };
int a[1001] = { 0, };
int a2[1001] = { 0, };
int idxcnt = 1;
int idxcnt2 = 1;

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int leng(int* arr) {
	int i;

	for (i = 1; i < 1001; i++)
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

//���� key�̰ų� key���� ���� ���� ū ��ġ ��ȯ
int searchindex(int key, int* a) {
	int i;
	int n = leng(a);

	for (i = 1; i < n; i++)
		if (a[i - 1] < key && key <= a[i])
			return i;

	return n;
}

int dpfunc(int* arr, int n) {

	//ù ���� ���� ũ�Ƿ� ���
	if (dp[1] == 0) {
		dp[idxcnt] = 1;
		a[1] = arr[1];
		idxcnt++;

		return a[1];
	}
	else {
		//�����ϴ� ������ ���ϴ� ��Ŀ����
		//arr[n] ���� ���� �Ÿ����� ª�� + �迭 a���� arr[n]�� ���� �ڸ��� �ִ� ���� arr[n]���� ũ�ų� ���� ��
		if (searchindex(arr[n], a) <= leng(dp) && a[searchindex(arr[n], a)] >= arr[n]) {
			//���Ӱ� �������ش�
			a[searchindex(arr[n], a)] = arr[n];
			dp[idxcnt] = searchindex(arr[n], a);
			idxcnt++;
		}
		else {
			//arr[n] ���� �Ÿ��� ������Ű�� ���ǿ� ���� ��
			dp[idxcnt] = searchindex(arr[n], a) + 1;
			a[searchindex(arr[n], a) + 1] = arr[n];
			idxcnt++;
		}
	}
}

int dpfunc2(int* b, int n) {

	//ù ���� ���� ũ�Ƿ� ���
	if (dp2[1] == 0) {
		dp2[idxcnt2] = 1;
		a2[1] = b[1];
		idxcnt2++;

		return a2[1];
	}
	else {
		//�����ϴ� ������ ���ϴ� ��Ŀ����
		//arr[n] ���� ���� �Ÿ����� ª�� + �迭 a���� arr[n]�� ���� �ڸ��� �ִ� ���� arr[n]���� ũ�ų� ���� ��
		if (searchindex(b[n], a2) <= leng(dp2) && a2[searchindex(b[n], a2)] >= b[n]) {
			//���Ӱ� �������ش�
			a2[searchindex(b[n], a2)] = b[n];
			dp2[idxcnt2] = searchindex(b[n], a2);
			idxcnt2++;
		}
		else {
			//arr[n] ���� �Ÿ��� ������Ű�� ���ǿ� ���� ��
			dp2[idxcnt2] = searchindex(b[n], a2) + 1;
			a2[searchindex(b[n], a2) + 1] = b[n];
			idxcnt2++;
		}
	}
}

//������ ������ �ݴ�� �ٲ��ش�
void redesign(int* arr, int n) {
	int mid = n / 2, i;

	if (n % 2 == 0) {
		for (i = 1; i <= mid; i++)
			swap(&arr[i], &arr[n - i + 1]);
	}
	else {
		for (i = 1; i <= mid; i++)
			swap(&arr[i], &arr[n - i + 1]);
	}
}

int main() {
	int n, i;

	scanf("%d", &n);
	int arr[1001] = { 0, };
	int b[1001] = { 0, };
	int realorder[1001] = { 0, };

	//input
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		b[i] = arr[i];
	}

	redesign(b, n);

	for (i = 1; i <= n; i++) {
		dpfunc(arr, i);
		dpfunc2(b, i);
	}

	for (i = 1; i <= n; i++)
		realorder[i] = dp[i] + dp2[n-i+1] - 1;

	printf("%d", realorder[maxindex(realorder)]);

	return 0;
}
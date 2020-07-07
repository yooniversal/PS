//15655

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20], ans[8];	//chk�� ������ ���� üũ�ϱ� ���� ����
int N, M, S, cnt = 0;

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 1000001);
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

void dfs(int idx) {
	int i;

	ans[cnt] = arr[idx];
	cnt++;

	//���� ����
	if (cnt == M) {
		for (int j = 0; j < M; j++)
			printf("%d ", ans[j]);
		printf("\n");
		return;
	}
	else {
		for (i = idx; i < N - 1; i++)	//N-1������ �ƴ϶� N-2���� ���ƾ� �Ѵ�(dfs(i+1)�̱� ����)
			if (!chk[i]) {		//�������� �ʾҴٸ�
				//chk[i] = 1;		//���������� üũ
				dfs(i + 1);		//�ڽ� ���� Ž��(depth search)
				//chk[i] = 0;		//���� Ž���� ������ ���� �ʵ��� üũ ����
				cnt--;
			}
	}
}

int main() {

	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		dfs(i);
		cnt = 0;	//�ʱ�ȭ�ؼ� ���� ���̽��� ������ ���� �ʾƾ� �Ѵ�
	}

	return 0;
}
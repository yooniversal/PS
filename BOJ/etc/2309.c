//2309

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20] = { 0 }, ans[7];	//chk�� ������ ���� üũ�ϱ� ���� ����
int S = 100, cnt = 0;					//cnt�� ���� ������ �ǹ�
int temp = 0;							//�� ���̽����� temp�� �����ϴ� ����

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

	temp += arr[idx];
	ans[cnt] = arr[idx];
	cnt++;

	//���� ����
	if (temp == S && cnt == 7) {

		mergesort(ans, 0, 6);

		for (int i = 0; i < 7; i++)
			printf("%d\n", ans[i]);

		exit(0);
	}
	else {
		for (i = idx; i<8; i++)	//N-1������ �ƴ϶� N-2���� ���ƾ� �Ѵ�(dfs(i+1)�̱� ����)
			if (!chk[i]) {		//�������� �ʾҴٸ�
				chk[i] = 1;		//���������� üũ
				dfs(i + 1);		//�ڽ� ���� Ž��(depth search)
				chk[i] = 0;		//���� Ž���� ������ ���� �ʵ��� üũ ����
				temp -= arr[i + 1];	//dfs(i+1)���� temp�� �߰��� ���� ����(���� Ž���� ������ ���� �ʵ���)
				cnt--;				//cnt�� 7�̻��̸� �ȵ�
			}
	}
}

int main() {

	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 3; i++) {
		dfs(i);
		temp = 0; //�������� temp, cnt�� �� ù��° ���̽��� �ݺ��� ������
		cnt = 0;  //�ʱ�ȭ�ż� ���� ���̽��� ������ ���� �ʾƾ� �Ѵ�
	}

	return 0;
}
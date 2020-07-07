//6603

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20], ans[6];	//chk�� ������ ���� üũ�ϱ� ���� ����
int N, S, cnt = 0;
int temp = 0;	//�� ���̽����� temp�� �����ϴ� ����

void dfs(int idx) {
	int i;

	ans[cnt] = arr[idx];		//temp�� ���� ���Ѵ�
	cnt++;

	//���� ����
	if (cnt == 6) {
		for (int j = 0; j < 6; j++)
			printf("%d ", ans[j]);
		printf("\n");
		return;
	}
	else {
		for (i = idx; i < N - 1; i++)	//N-1������ �ƴ϶� N-2���� ���ƾ� �Ѵ�(dfs(i+1)�̱� ����)
			if (!chk[i]) {		//�������� �ʾҴٸ�
				chk[i] = 1;		//���������� üũ
				dfs(i + 1);		//�ڽ� ���� Ž��(depth search)
				chk[i] = 0;		//���� Ž���� ������ ���� �ʵ��� üũ ����
				cnt--;
			}
	}
}

int main() {

	while (1) {
		scanf("%d", &N);
		if (N == 0) return 0;

		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		for (int i = 0; i < N-5; i++) {
			dfs(i);
			temp = 0;	//�������� temp�� �� ù��° ���̽��� �ݺ��� ������
			cnt = 0;	//�ʱ�ȭ�ؼ� ���� ���̽��� ������ ���� �ʾƾ� �Ѵ�
		}
		printf("\n");
	}

	return 0;
}
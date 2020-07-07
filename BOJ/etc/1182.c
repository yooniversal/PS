//1182

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20] = { 0 };	//chk�� ������ ���� üũ�ϱ� ���� ����
int N, S, cnt = 0;
int temp = 0;	//�� ���̽����� temp�� �����ϴ� ����

void dfs(int idx) {
	int i;

	temp += arr[idx];		//temp�� ���� ���Ѵ�
	if (temp == S) cnt++;	//�����̸� ���� ī��Ʈ ����
	
	//���� ����
	if (idx == N - 1) return;	//������ ������ �� ����
	else {
		for (i = idx; i < N-1; i++)	//N-1������ �ƴ϶� N-2���� ���ƾ� �Ѵ�(dfs(i+1)�̱� ����)
			if (!chk[i]) {		//�������� �ʾҴٸ�
				chk[i] = 1;		//���������� üũ
				dfs(i + 1);		//�ڽ� ���� Ž��(depth search)
				chk[i] = 0;		//���� Ž���� ������ ���� �ʵ��� üũ ����
				temp -= arr[i+1];	//dfs(i+1)���� temp�� �߰��� ���� ����(���� Ž���� ������ ���� �ʵ���)
			}
	}
}

int main(){

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		dfs(i);
		temp = 0; //�������� temp�� �� ù��° ���̽��� �ݺ��� ������
				  //�ʱ�ȭ�ؼ� ���� ���̽��� ������ ���� �ʾƾ� �Ѵ�
	}

	printf("%d", cnt);

	return 0;
}
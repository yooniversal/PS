//4949

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, idx=0;
	char arr[101], brr[101] = {"",};

	while(1) {
		gets(arr);

		//�� �ϳ��� ������ �����Ѵ�
		if (arr[0] == '.') return 0;

		for (i = 0; i < strlen(arr); i++) {
			if (arr[i] == '(') {
				brr[idx] = '(';
				idx++;
			}
			else if (arr[i] == ')') {
				if (brr[idx - 1] == '(' && idx > 0) {
					brr[idx - 1] = " ";
					idx--;
				}
				else {
					idx = -1;
					break;
				}
			}
			else if (arr[i] == '[') {
				brr[idx] = '[';
				idx++;
			}
			else if (arr[i] == ']') {
				if (brr[idx - 1] == '[' && idx>0) {
					brr[idx - 1] == " ";
					idx--;
				}
				else {
					idx = -1;
					break;
				}
			}
			//��ȣ �̿� ���ڴ� ����
			else
				continue;
		}

		//printf("brr : ");
		//	printf("%s\n", brr);

		if (idx == 0) printf("yes\n");
		else printf("no\n");
		idx = 0;

		memset(brr, 0, sizeof(brr));
	}

	return 0;
}